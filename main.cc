// Chifor Darius

//=> includes ---
#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
using d64 = long double;
//|=> includes ^

//=> classes ---
class ymd {
public:
  i64 year = 1970;
  i64 month = 1;
  i64 day = 1;
};
ymd default_ymd;

class driver {
public:
  i64 number = 0;
  string code = "";
  string forename = "";
  string surname = "";
  string nationality = "";
  ymd birthday;

  i64 id = 0;
  string refname = "";
  string wikiurl = "";
};
driver default_driver;

class circuit {
public:
  string name = "";
  string city = "";
  string country = "";
  d64 latitude = 0.0;
  d64 longitude = 0.0;

  i64 alt = 0; //* TODO: figure out what this is

  i64 id = 0;
  string refname = "";
  string wikiurl = "";
};
circuit default_circuit;
//|=> classes and defaults ^

//=> read functions ---
void read_drivers(vector<driver> &v) {
  ifstream sdrivers{"drivers.csv"};
  string s;

  getline(sdrivers, s);
  while (true) {
    getline(sdrivers, s);
    if (s.empty()) {
      break;
    }
    stringstream ss(s);

    getline(ss, s, ',');
    i64 i = stoi(s);
    while (v.size() <= i) {
      v.push_back(default_driver);
    }
    v[i].id = i;

    getline(ss, s, ',');
    v[i].refname = s.substr(1, s.size() - 2);
    getline(ss, s, ',');
    if (s != "\\N") {
      v[i].number = stoi(s);
    }
    getline(ss, s, ',');
    v[i].code = s.substr(1, s.size() - 2);
    getline(ss, s, ',');
    v[i].forename = s.substr(1, s.size() - 2);
    getline(ss, s, ',');
    v[i].surname = s.substr(1, s.size() - 2);
    getline(ss, s, ',');
    v[i].birthday.year = stoi(s.substr(1, 4));
    v[i].birthday.month = stoi(s.substr(6, 2));
    v[i].birthday.day = stoi(s.substr(9, 2));
    getline(ss, s, ',');
    v[i].nationality = s.substr(1, s.size() - 2);
    getline(ss, s, ',');
    v[i].wikiurl = s.substr(1, s.size() - 2);
  }
}

void read_circuits(vector<circuit> &v) {
  ifstream scircuits{"circuits.csv"};
  string s;

  getline(scircuits, s);
  while (true) {
    getline(scircuits, s);
    if (s.empty()) {
      break;
    }
    stringstream ss(s);

    getline(ss, s, ',');
    i64 i = stoi(s);
    while (v.size() <= i) {
      v.push_back(default_circuit);
    }
    v[i].id = i;

    getline(ss, s, ',');
    v[i].refname = s.substr(1, s.size() - 2);
    getline(ss, s, ',');
    v[i].name = s.substr(1, s.size() - 2);
    getline(ss, s, ',');
    v[i].city = s.substr(1, s.size() - 2);
    getline(ss, s, ',');
    v[i].country = s.substr(1, s.size() - 2);
    getline(ss, s, ',');
    v[i].latitude = stod(s);
    getline(ss, s, ',');
    v[i].longitude = stod(s);
    getline(ss, s, ',');
    if (s != "\\N") {
      v[i].alt = stoi(s);
    }
    getline(ss, s, ',');
    v[i].wikiurl = s.substr(1, s.size() - 2);
  }
}
//|=> read functions ^

int main() {
  ofstream cout{"output.log"};

  ifstream sconstructorres{"constructor_results.csv"};
  ifstream sconstructorstandings{"constructor_standings.csv"};
  ifstream sconstructors{"constructors.csv"};
  ifstream sdriverstandings{"driver_standings.csv"};
  ifstream slaptimes{"lap_times.csv"};
  ifstream spitstops{"pit_stops.csv"};
  ifstream squali{"quialifying.csv"};
  ifstream sraces{"races.csv"};
  ifstream sresults{"results.csv"};
  ifstream sseansons{"seasons.csv"};
  ifstream ssprintres{"sprint_results.csv"};
  ifstream sstatus{"status.csv"};

  vector<driver> drivers;
  read_drivers(drivers);
  vector<circuit> circuits;
  read_circuits(circuits);

  for (i64 i = 0; i < drivers.size(); i++) {
    auto e = drivers[i];

    if (i != e.id) {
      cout << "i: " << i << " id: " << e.id << endl;
    }
  }

  return 0;
}

/*
"1985-01-07"
0123456789
*/