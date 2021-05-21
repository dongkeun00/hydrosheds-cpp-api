#include "hydrosheds/hydrosheds.hh"

#include "ogrsf_frmts.h"

#include<iostream>


using namespaces hydrosheds;

//HadroshedsDataSet

//HydroshedsData constructor
HydroshedsDataSet::HydroshedsDataSet(char* s)
{
  GDALAllRegister();

layer = poDS->GetLayerByName(s);

}

//give Data to RiverSegment
RiverSegment HydroshedsDataSet::getSegment() const
{

}



//RiverSegment
//RiverSegment constructor
RiverSegment::RiverSegment(OGRFeature *b, unsigned int c)
{
  this->c;
  auto feature = p->getFeature();
  OGRLayer *layer;
  feature=layer->getFeature(c);
}


//get Length
double RiverSegment::getLength() const
{
  virtual void segmentize(double dfMaxLength)
  {
    //calculate value between start and end point dont really know how to if points are missing 
    //dfMaxLength = 
  }
}

//get geological Length
double RiverSegment::getGeologicalLength() const
{
  //maybe we can use a scale and use the same method like in get length?
}

//get Discharge
double RiverSegment::getDischarge() const
{

}



//get starting Point of RiverSegment
Coordinate RiverSegment::getStartingPoint() const
{
  //set Dimension to 2
  virtual void setCoordinateDimension(int nDimension) override{
    int nDimension=2;
    //get geometric attributes
    OGRGeometry *pGeo = feature->getGeometryRef;
    //fetch geometry from container
    OGRGeometry *getGeometryRef(int i);
    //reference for point
    OGRPoint *point = &pGeo;

    Coordinate segEnd;
    //get coordinates, not sure if this actually works
    segStart[0] = point -> getX();
    segStart[1] = point -> getY();


}

//get ending Point of RiverSegment
Coordinate RiverSegment::getEndPoint()
{
  //set Dimension to 2
  virtual void setCoordinateDimension(int nDimension) override{
    int nDimension=2;
    //get geometric attributes
    OGRGeometry *pGeo = feature->getGeometryRef;
    //fetch geometry from container
    OGRGeometry *getGeometryRef(int i);
    //reference for point
    OGRPoint *point = &pGeo;

    Coordinate segEnd;
    //get coordinates, not sure if this actually works
    //dont really know how to get the endpoint if the code is for the start
    segEnd[0] = point -> getX();
    segEnd[1] = point -> getY();

  }
  

}


//show if Riversegment has Downstream
bool RiverSegment::hasDownstreamSegment() const
{
  //Idee: Falls Endpunkt von RiverSegment != Startpunkt von NextRiverSegment return false, else true
  /*auto *poDS = feature-> getNextRiverSegment();

  if(segEnd!=getNextRiverSegment()){
    return false;
  }
  else 
    return true;
*/
}

//get the Down Stream Segment if RiverSegment has one
double RiverSegment::getDownstreamSegment() const
{

}

//



int main(int argc, char** argv)
{
  if (argc != 2) {
    std::cerr << "Usage: ./hydrosheds_app <path-to-gdb-directory>" << std::endl;
    return 1;
  }

  GDALAllRegister();

  GDALDataset* data;
  data = (GDALDataset*) GDALOpenEx(argv[1], GDAL_OF_VECTOR, NULL, NULL, NULL );

  if(data == NULL)
  {
      std::cerr << "Opening geodatabase failed." << std::endl;
      return 1;
  }

  std::cout << "Layer count in GeoDataBase: " << data->GetLayerCount() << std::endl;
  std::cout << "Test" << std::endl;


  // Extract the first layer
  auto layer = data->GetLayer(0);
  
  // Extract first feature
  auto feature = layer->GetNextFeature();
  feature->DumpReadable(NULL, NULL);
  
  return 0;
}