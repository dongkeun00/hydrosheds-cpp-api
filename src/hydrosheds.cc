#include "hydrosheds/hydrosheds.hh"

#include "ogrsf_frmts.h"

#include<iostream>
#include<string>
#include<math.h>

namespace hydrosheds {

  HydroshedsDataSet::HydroshedsDataSet(const std::string& path)
  {
    GDALAllRegister();
    auto data = (GDALDataset*) GDALOpenEx(path.c_str(), GDAL_OF_VECTOR, NULL, NULL, NULL);

    if(data == NULL)
    {
      std::cerr << "Opening geodatabase failed." << std::endl;
      throw std::exception{};
    }

    layer = data->GetLayer(0);
  }

  RiverSegment HydroshedsDataSet::getSegment() const
  {
    // This is extracting just some random feature for debugging purposes.
    // When we move on to iterators, this will vanish.
    return RiverSegment(layer, layer->GetFeature(89));
  }

  RiverSegment::RiverSegment(OGRLayer* layer, OGRFeature* feature)
    : layer(layer)
    , feature(feature)
  {}

  RiverSegment RiverSegment::getDownstreamSegment() const
  {
    // The modulo operation here is weird, but necessary if the GetFeature(index)
    // method is supposed to be used: It removes the continent encoding prefix
    auto next_index = feature->GetFieldAsInteger("NEXT_DOWN") % 10000000;
    return RiverSegment(layer, layer->GetFeature(next_index));
  }

  double RiverSegment::getDischarge() const
  {
    return feature->GetFieldAsDouble("DIS_AV_CMS");
  }

  Coordinate RiverSegment::getStartingPoint() const
  {
    // Get the most specific GDAL object that we can find that represents our curve
    OGRGeometry* geo = feature->GetGeometryRef();
    OGRMultiLineString* multiline = geo->toMultiLineString();
    OGRLineString* line = *(multiline->begin());

    // Extract the curve start point
    OGRPoint start;
    line->StartPoint(&start);

    return Coordinate{start.getX(), start.getY()};
  }

  Coordinate RiverSegment::getEndPoint() const
  {
    // TODO: TASK
    OGRGeometry* geo = feature->GetGeometryRef();
    OGRMultiLineString* multiline = geo->toMultiLineString();
    OGRLineString* line = *(multiline->begin());

    OGRPoint start;
    line->EndPoint(&start);

     return Coordinate{start.getX(), start.getY()};
  }
//had no idea how to implement this one
  /*bool RiverSegment::hasDownstreamSegment() const
  {
    // TODO: TASK
    OGRGeometry* down = feature->GetGeometryRef();
    OGRMultiLineString* multiline = geo->toMultiLineString();
    OGRLineString* line = *(multiline->begin());
    
    if( )

    return 0;
  }*/

  double RiverSegment::getLength() const
  {
    // TODO: TASK
    OGRGeometry* geo = feature->GetGeometryRef();
    OGRMultiLineString* multiline = geo->toMultiLineString();
    OGRLineString* line = *(multiline->begin());
    OGRPoint start;
    line->StartPoint(&start);
    OGRPoint end;
    line->EndPoint(&end);

    auto x = pow(end.getX()-start.getX(),2);
    auto y = pow(end.getY()-start.getY(),2);
    auto length = sqrt(x+y);
    return length;
    }

  double RiverSegment::getGeologicalLength() const
  {
    // TODO: TASK
    OGRGeometry* geo = feature->GetGeometryRef();
    OGRMultiLineString* multiline = geo->toMultiLineString();
    OGRLineString* line = *(multiline->begin());
    OGRPoint start;

    auto geolength = line->get_Length();
    return geolength;  
    }

} // namespace hydrosheds