#pragma once

#include "hydrosheds/hydrosheds.hh"

#include<array>
#include<string>
#include<vector>

namespace hydrosheds {

  class RasterizedHydroshedsDataset
  {
    public:
    //! Construct a rasterized dataset from a vector dataset
    RasterizedHydroshedsDataset(
      HydroshedsDataSet,
      std::array<unsigned int, 2>,
      Coordinate,
      Coordinate
    );

    //! Return whether a certain pixel coordinate is coloured or not
    bool operator[](const std::array<unsigned int, 2>& a) const;

    //! Dump image into file
    void writeToFile(const std::string&) const;


      hydrosheds::Coordinate translate();

    void print();

    private:
    std::vector<std::vector<bool>> data;
      hydrosheds::Coordinate t;
  };

} // namespace hyrosheds
