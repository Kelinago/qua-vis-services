#include "geojson.hpp"

#include <vector>

void test_square_with_hole() {
  std::vector<geojson::vec3> polygon = {
    {0,0,0},
    {0,1,0},
    {1,1,0},
    {1,0,0},
    {0,0,0},
    {.25,.25,0},
    {.75,.25,0},
    {.75,.75,0},
    {.25,.75,0},
    {.25,.25,0}
  };

  std::vector<geojson::vec3> expected = {
    {0.000000,1.000000,0.000000},
    {1.000000,1.000000,0.000000},
    {0.750000,0.750000,0.000000},
    {0.000000,1.000000,0.000000},
    {0.750000,0.750000,0.000000},
    {0.250000,0.750000,0.000000},
    {0.000000,1.000000,0.000000},
    {0.250000,0.750000,0.000000},
    {0.250000,0.250000,0.000000},
    {0.750000,0.250000,0.000000},
    {0.750000,0.750000,0.000000},
    {1.000000,1.000000,0.000000},
    {0.750000,0.250000,0.000000},
    {1.000000,1.000000,0.000000},
    {1.000000,0.000000,0.000000},
    {0.750000,0.250000,0.000000},
    {1.000000,0.000000,0.000000},
    {0.000000,0.000000,0.000000},
    {0.000000,0.000000,0.000000},
    {0.000000,1.000000,0.000000},
    {0.250000,0.250000,0.000000},
    {0.000000,0.000000,0.000000},
    {0.250000,0.250000,0.000000},
    {0.750000,0.250000,0.000000}
  };

  std::vector<geojson::vec3> result = triangulate(polygon);
  for (size_t i = 0; i < result.size(); i++) {
    if(!(result[i] == expected[i])) throw;
  }
}

void test_with_two_holes() {
  std::vector<geojson::vec3> polygon = {
    {-3,-3,0},
    {-3,3,0},
    {3,3,0},
    {3,-3,0},
    {-3,-3,0},
    {0.5,0,0},
    {0.5,-1,0},
    {1,0,0},
    {0.5,1,0},
    {-0.5,1,0},
    {-1,0,0},
    {-0.5,-1,0},
    {-0.5,0,0},
    {0.5,0,0},
    {2.25,2.25,0},
    {2.75,2.25,0},
    {2.75,2.75,0},
    {2.25,2.75,0},
    {2.25,2.25,0},
  };

  std::vector<geojson::vec3> expected = {
    {-3.000000,3.000000,0.000000},
    {3.000000,3.000000,0.000000},
    {2.750000,2.750000,0.000000},
    {-3.000000,3.000000,0.000000},
    {2.750000,2.750000,0.000000},
    {2.250000,2.750000,0.000000},
    {-3.000000,3.000000,0.000000},
    {2.250000,2.750000,0.000000},
    {2.250000,2.250000,0.000000},
    {-3.000000,3.000000,0.000000},
    {2.250000,2.250000,0.000000},
    {0.500000,1.000000,0.000000},
    {-3.000000,3.000000,0.000000},
    {0.500000,1.000000,0.000000},
    {-0.500000,1.000000,0.000000},
    {-3.000000,3.000000,0.000000},
    {-0.500000,1.000000,0.000000},
    {-1.000000,0.000000,0.000000},
    {-3.000000,3.000000,0.000000},
    {-1.000000,0.000000,0.000000},
    {-0.500000,-1.000000,0.000000},
    {-0.500000,-1.000000,0.000000},
    {-0.500000,0.000000,0.000000},
    {0.500000,0.000000,0.000000},
    {-0.500000,-1.000000,0.000000},
    {0.500000,0.000000,0.000000},
    {0.500000,-1.000000,0.000000},
    {1.000000,0.000000,0.000000},
    {0.500000,1.000000,0.000000},
    {2.250000,2.250000,0.000000},
    {1.000000,0.000000,0.000000},
    {2.250000,2.250000,0.000000},
    {2.750000,2.250000,0.000000},
    {2.750000,2.250000,0.000000},
    {2.750000,2.750000,0.000000},
    {3.000000,3.000000,0.000000},
    {2.750000,2.250000,0.000000},
    {3.000000,3.000000,0.000000},
    {3.000000,-3.000000,0.000000},
    {-3.000000,-3.000000,0.000000},
    {-3.000000,3.000000,0.000000},
    {-0.500000,-1.000000,0.000000},
    {-3.000000,-3.000000,0.000000},
    {-0.500000,-1.000000,0.000000},
    {0.500000,-1.000000,0.000000},
    {0.500000,-1.000000,0.000000},
    {1.000000,0.000000,0.000000},
    {2.750000,2.250000,0.000000},
    {0.500000,-1.000000,0.000000},
    {2.750000,2.250000,0.000000},
    {3.000000,-3.000000,0.000000},
    {-3.000000,-3.000000,0.000000},
    {0.500000,-1.000000,0.000000},
    {3.000000,-3.000000,0.000000}
  };

  std::vector<geojson::vec3> result = triangulate(polygon);
  for (size_t i = 0; i < result.size(); i++) {
    if(!(result[i] == expected[i])) throw;
  }
}

void test_square() {
  std::vector<geojson::vec3> polygon = {
    {0,0,0},
    {0,1,0},
    {1,1,0},
    {1,0,0},
    {0,0,0}
  };

  std::vector<geojson::vec3> expected = {
    {0,0,0},
    {0,1,0},
    {1,1,0},
    {0,0,0},
    {1,1,0},
    {1,0,0}
  };

  std::vector<geojson::vec3> result = triangulate(polygon);
  for (size_t i = 0; i < result.size(); i++) {
    if(!(result[i] == expected[i])) throw;
  }
}

void test_rotated_square() {
  std::vector<geojson::vec3> polygon = {
    {0,0,1},
    {0,1,1},
    {1,1,0},
    {1,0,0},
    {0,0,1}
  };

  std::vector<geojson::vec3> expected = {
    {0,0,1},
    {0,1,1},
    {1,1,0},
    {0,0,1},
    {1,1,0},
    {1,0,0}
  };

  std::vector<geojson::vec3> result = triangulate(polygon);
  for (size_t i = 0; i < result.size(); i++) {
    if(!(result[i] == expected[i])) throw;
  }
}

void test_polygon_no_holes() {
  std::vector<geojson::vec3> polygon = {
    {0.5,0,0},
    {0.5,-1,0},
    {1,0,0},
    {0.5,1,0},
    {-0.5,1,0},
    {-1,0,0},
    {-0.5,-1,0},
    {-0.5,0,0},
    {0.5,0,0}
  };

  std::vector<geojson::vec3> expected = {
    {0.500000,0.000000,0.000000},
    {0.500000,-1.000000,0.000000},
    {1.000000,0.000000,0.000000},
    {0.500000,0.000000,0.000000},
    {1.000000,0.000000,0.000000},
    {0.500000,1.000000,0.000000},
    {0.500000,0.000000,0.000000},
    {0.500000,1.000000,0.000000},
    {-0.500000,1.000000,0.000000},
    {-1.000000,0.000000,0.000000},
    {-0.500000,-1.000000,0.000000},
    {-0.500000,0.000000,0.000000},
    {-0.500000,0.000000,0.000000},
    {0.500000,0.000000,0.000000},
    {-0.500000,1.000000,0.000000},
    {-0.500000,1.000000,0.000000},
    {-1.000000,0.000000,0.000000},
    {-0.500000,0.000000,0.000000}
  };

  std::vector<geojson::vec3> result = triangulate(polygon);
  for (size_t i = 0; i < result.size(); i++) {
    if(!(result[i] == expected[i])) throw;
  }
}

int main() {
  test_square();
  test_rotated_square();
  test_polygon_no_holes();
  test_square_with_hole();
  test_with_two_holes();
}
