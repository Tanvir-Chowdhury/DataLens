// Graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include "Database.h"
#include "matplot/axes_objects/histogram.h"
#include <algorithm>
#include <matplot/matplot.h>
#include <string>
#include <vector>

class Graph {
public:
  void heightDistribution(Database *d);
  void weightDistribution(Database *d);
  void genderDistribution(Database *d);
  void totalNOofMedalsbyCountry(Database *d);
};

#endif // GRAPH_H
