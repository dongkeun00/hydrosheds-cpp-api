#include "hydrosheds/rasterize.hh"
#include <iostream>
#include<tiffio.h>

namespace hydrosheds {

  RasterizedHydroshedsDataset::RasterizedHydroshedsDataset(
      HydroshedsDataSet dataset,
      std::array<unsigned int, 2> resolution,
      Coordinate lowerleft,
      Coordinate upperright
    )
  {
      //size of the segment
      double horizontal_length = upperright[0]-lowerleft[0];
      double vertical_length = upperright[1]-lowerleft[1];
    //lowerleft[0] = 0;
    //lowerleft[1] = 0;

    //size of the segment
      data.resize(resolution[1]);

      for(auto& i : data)
      {
          i.resize(resolution[0], false);
      }

    // for(auto it: dataset)
    // Maybe some coordinate
    // hydrosheds::Coordinate x ={}
    // for(auto it : hydrosheds::impl::followstream(dataset, x)
//for Schleife für Klasse

      auto Segment = dataset.getSegment();/*
      auto start = Segment.getStartingPoint();
      auto end = Segment.getEndPoint();
*/
    //set coordinations for test purposes
      hydrosheds::Coordinate start = {1,2};
      hydrosheds::Coordinate end = {10, 12};

      double x1 = start[0];
      double x2 = start[1];

      double y1 = end[0];
      double y2 = end[1];

      //data[x1][x2]=true;
      //data[y1][y2]=true;

    //t is the ratio/proportion from the matrix and the pixel matrix
    //t = {(upperright[0] - lowerleft[0])/resolution[0], (upperright[1] - lowerleft[1])/resolution[1]};
    t = {horizontal_length/resolution[0], vertical_length/resolution[1]};
    std::cout<< upperright[0]<<std::endl;
    std::cout<< upperright[1]<<std::endl;
    std::cout<< lowerleft[0]<<std::endl;
    std::cout<< lowerleft[1]<<std::endl;
    std::cout<< t[0] << std::endl;
    std::cout<< t[1] << std::endl;
    
    std::cout << "the relation: " << t[0] << " / " << t[1] << std::endl;

    //m=incline
      double m = (y2 -y1)/(x2 - x1);
        std::cout<< m <<std::endl;
      double x=x1;

    //it seems that the formula doesn't seems to work well
      for(double i = x1; i<y1; i+=t[0])
      {
          double j = m *(i -1) +x2;
          //hydrosheds::Coordinate pxCoord;
          int x1t = static_cast <int>(( i - lowerleft[0]) / t[0]);
          //int x2t = static_cast <int>(((m * i +x2) - lowerleft[1]) / t[1]);
          int x2t = static_cast <int>((j - lowerleft[1]) / t[1]);
  
          data[x1t][x2t]=true;
      }

      for(double u = x2; u<y2; u+=t[1])
      {
        double v = (u - 1) / m ;
        
        int p1t = static_cast <int>(( u - lowerleft[0]) / t[0]);
          
        int p2t = static_cast <int>((v - lowerleft[1]) / t[1]);
        //data[p1t][p2t]= true;
      }




  }

  bool RasterizedHydroshedsDataset::operator[](const std::array<unsigned int, 2>& a) const
  {
      return data[a[0]][a[1]];
  }



    /*void RasterizedHydroshedsDataset::writeToFile(const std::string& filename) const
  {
    // TODO e.g. using code from this StackOverflow post:
    // https://stackoverflow.com/questions/50770906/32bit-tif-image-read-and-write-using-libtiff-library-c
  // Problem with using width(vertical_length) and height(vertical_length)
 // also scan_line doesn't work
    //---------------reading part------------------
    TIFF* tif = TIFFOpen(filename.c_str(),  "r");

    TIFFGetField(tif, TIFFTAG_IMAGEWIDTH, &vertical_length);
    TIFFGetField(tif, TIFFTAG_IMAGELENGTH, &horizontal_length;
    uint32* buffer = (uint32 *)malloc(horizontal_length*vertical_length * sizeof(uint32));
    TIFFReadRawStrip(tif, 0, buffer, horizontal_length*vertical_length);

//---------------writing part------------------

    TIFF *image = TIFFOpen("input.tif", "w");
    TIFFSetField(image, TIFFTAG_IMAGEWIDTH, horizontal_length); 
    TIFFSetField(image, TIFFTAG_IMAGELENGTH, vertical_length); 
    TIFFSetField(image, TIFFTAG_BITSPERSAMPLE, 32); 
    TIFFSetField(image, TIFFTAG_SAMPLESPERPIXEL, 1); 
    TIFFSetField(image, TIFFTAG_ROWSPERSTRIP, 1);   
    TIFFSetField(image, TIFFTAG_ORIENTATION, ORIENTATION_TOPLEFT);
    TIFFSetField(image, TIFFTAG_PLANARCONFIG, PLANARCONFIG_CONTIG);
    TIFFSetField(image, TIFFTAG_PHOTOMETRIC, PHOTOMETRIC_MINISBLACK);
    TIFFSetField(image, TIFFTAG_SAMPLEFORMAT, SAMPLEFORMAT_UINT);
    TIFFSetField(image, TIFFTAG_COMPRESSION, COMPRESSION_NONE);

    auto scan_line = (uint32 *)malloc(horizontal_length*(sizeof(uint32)));

    for (int i = 0; i < vertical_length; i++) //loading the data into a buffer
            {
                TIFFReadScanline(tif, scan_line, i);
                memcpy(&buffer[i*horizontal_length], scan_line, vertical_length * sizeof(uint32));

            }

    TIFFClose(image);
    TIFFClose(tif);
    free(buffer);
    free(scan_line);

  }

}*/
    //for testing purpose
  void RasterizedHydroshedsDataset::print()
  {
      for(auto  j : data)
      {
          for (auto i : j)
          {
              if(i)
              {
                  std::cout << " 1 ";
              }else{
                  std::cout << " 0 ";
              }
          }
          std::cout << std::endl;
      }
  }

}