#include "hydrosheds/hydrosheds.hh"

#include<iostream>


int main(int argc, char** argv)
{
  if (argc != 2) {
    std::cerr << "Usage: ./hydrosheds_app <path-to-gdb-directory>" << std::endl;
    return 1;
  }

  // Instantiate the data set
  hydrosheds::HydroshedsDataSet dataset(argv[1]);

  // Printing some example data
  auto segment = dataset.getSegment();
  auto start = segment.getDownstreamSegment().getStartingPoint();
  auto end = segment.getDownstreamSegment().getEndPoint();
  std::cout << end[0] << " " << end[1] << std::endl;
  std::cout << start[0] << " " << start[1] << std::endl;

  auto length = segment.getLength();
  std::cout<<length<<std::endl;

  auto geolength = segment.getGeologicalLength();
  std::cout<<geolength<<std::endl;

  return 0;
}