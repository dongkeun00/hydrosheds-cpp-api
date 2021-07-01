#include "hydrosheds/rasterize.hh"

#include<iostream>


int main(int argc, char** argv)
{
    /*
  if (argc != 2) {
    std::cerr << "Usage: ./rasterize_app <path-to-gdb-directory>" << std::endl;
    return 1;
  }
*/
    std::string tmp ="/home/dongkeun/Documents/HydroRIVERS_v10_eu.gdb/HydroRIVERS_v10_eu.gdb";
  // Instantiate the data set
  hydrosheds::HydroshedsDataSet dataset(tmp);

  // And the rasterized version of it
  hydrosheds::RasterizedHydroshedsDataset rasterdataset(dataset, {40, 20}, {0.0, 0.0}, {20.0, 20.0});

    //hydrosheds::RasterizedHydroshedsDataset rasterdataset(dataset);
    rasterdataset.print();
  // Print one pixel value
  std::cout << "Value of first pixel: " << (rasterdataset[{0, 0}] ? "true" : "false" ) << std::endl;
}
