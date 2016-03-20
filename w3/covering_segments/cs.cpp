#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
    int start, end;
/*    void print() {*/
      //std::cout << start << '\t' << end << '\n';
    /*}*/
    bool covers(int point) {
        return (point >= start && point <= end);
    }
};

bool compare_segment(const Segment& s1, const Segment& s2) {
    return s1.end < s2.end;
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  for (size_t i = 0; i < segments.size(); ++i) {
    Segment s = segments[i];
    if (i==0){
        points.push_back(s.end);
        continue;
    }
    if (s.covers(points.back()))
        continue;
    else points.push_back(s.end);

  }
  return points;
}

int main() {
    int n;
    std::cin >> n;
    vector<Segment> segments(n);
    for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
    }

    std::sort(segments.begin(), segments.end(), compare_segment);

    //for (size_t i = 0; i< segments.size(); i++) {
        //segments[i].print();
    //}


    vector<int> points = optimal_points(segments);
    std::cout << points.size() << "\n";
    
    for (size_t i = 0; i < points.size(); ++i) {
        std::cout << points[i] << " ";
    }
}
