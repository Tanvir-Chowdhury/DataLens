// Graph.cpp

// Graph.cpp
#include "Graphs.h"
#include "matplot/freestanding/plot.h"
//#include <algorithm>
#include <iostream>
//#include <stdexcept>
#include <windows.h>

using namespace std;
using namespace matplot;

void Graph::heightDistribution(Database *d) {
  vector<string> *heights = new vector<string>();
  vector<double> heightd;
  d->getTable("athletes.csv")->returnColumn(9, heights);

  for (const string &s : *heights) {
    try {
      heightd.push_back(stod(s));
    } catch (const invalid_argument &e) {
      cerr << "Invalid input: '" << s << "' cannot be converted to double"
           << endl;
    } catch (const out_of_range &e) {
      cerr << "Out of range error: '" << s << "' is too large to be a double"
           << endl;
    }
  }

  delete heights; // Clean up dynamically allocated memory

  vector<double> filtered_heights;
  copy_if(heightd.begin(), heightd.end(), back_inserter(filtered_heights),
          [](double h) { return h > 0.0; });

  auto h = hist(filtered_heights); // 10 bins for the histogram

  title("Height Distribution of Athletes");
  xlabel("Height (cm)");
  ylabel("Number of Athletes");

  h->face_color("red");

  string save_path = "/home/sujat/projects/CSE225-summer24-project/charts/"
                     "height_distribution.jpg";
  save(save_path);
}

void Graph::weightDistribution(Database *d) {
  vector<string> *weights = new vector<string>();
  vector<double> weightd;

  d->getTable("athletes.csv")->returnColumn(10, weights);

  for (const string &s : *weights) {
    try {
      weightd.push_back(stod(s));
    } catch (const invalid_argument &e) {
      cerr << "Invalid input: '" << s << "' cannot be converted to double"
           << endl;
    } catch (const out_of_range &e) {
      cerr << "Out of range error: '" << s << "' is too large to be a double"
           << endl;
    }
  }

  delete weights; // Clean up dynamically allocated memory

  vector<double> filtered_weights;
  copy_if(weightd.begin(), weightd.end(), back_inserter(filtered_weights),
          [](double h) { return h > 0.0; });

  auto h = hist(filtered_weights); // 10 bins for the histogram

  title("Weight Distribution of Athletes");
  xlabel("Weight (kg)");
  ylabel("Number of Athletes");

  h->face_color("red");

  string save_path = "/home/sujat/projects/CSE225-summer24-project/charts/"
                     "weight_distribution.jpg";
  save(save_path);
}

void Graph ::genderDistribution(Database *d) {

  vector<string> *genders = new vector<string>();
  int male_counter = 0;
  int female_counter = 0;
  d->getTable("athletes.csv")->returnColumn(4, genders);
  for (const string &s : *genders) {
    if (s == "Male") {
      male_counter++;
    } else if (s == "Female") {

      female_counter++;
    }
  }
  delete genders; // Clean up dynamically allocated memory
  cout << male_counter << endl;
  cout << female_counter << endl;

  vector<int> counts = {male_counter, female_counter};

  auto b = bar(counts);

  title("Gender Distribution of Athletes");
  xlabel("Gender");
  ylabel("Number of Athletes");
  gca()->x_axis().ticklabels({"Male", "Female"});
  std::array<float, 4> blue = {0.0f, 0.0f, 1.0f, 1.0f};  // RGBA for blue
  std::array<float, 4> pink = {1.0f, 0.75f, 0.8f, 1.0f}; // RGBA for pink
  std::vector<std::array<float, 4>> colors = {blue, pink};

  b->face_colors(colors); // Assign colors to bars
  string save_path = "/home/sujat/projects/CSE225-summer24-project/charts/"
                     "gender_distribution.jpg";
  save(save_path);
}
void Graph::totalNOofMedalsbyCountry(Database *d) {

  std::vector<std::string> *countries = new std::vector<std::string>();
  d->getTable("medals_total.csv")->returnColumn(0, countries);

  std::vector<std::string> *total_medals = new std::vector<std::string>();
  d->getTable("medals_total.csv")->returnColumn(6, total_medals);

  std::vector<int> int_medals;

  // Loop through the total_medals vector, convert each element to an integer
  // and push it to int_medals
  for (const std::string &medal : *total_medals) {
    try {
      int_medals.push_back(stod(medal));
    } catch (const invalid_argument &e) {
      cerr << "Invalid input: '" << medal << "' cannot be converted to double"
           << endl;
    } catch (const out_of_range &e) {
      cerr << "Out of range error: '" << medal << "' is too large to be a double"
           << endl;
    }
  }

   auto b = bar(int_medals);
  // b->face_color(map_values(total_medals));
   gca()->x_axis().ticklabels(*countries);

   title("Number of Medals by Country");
   xlabel("Country Code");
   ylabel("Number of Medals");
  string save_path = "/home/sujat/projects/CSE225-summer24-project/charts/"
                     "medals_by_country.jpg";
  save(save_path);

}
