#include<bits/stdc++.h>
using namespace std;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;

  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }

  void swap(vector<int>& data_, int x,int y)
  {
    int temp = data_[x];
    data_[x] = data_[y];
    data_[y] = temp;
  }

  void sift_down(int curr,int limit,vector<int>& data_)
  {
    int l_child = 2*curr + 1, r_child, min_idx;
    while(l_child<=limit)
    {
      r_child = 2*curr + 2;
      if((r_child <= limit) && (data_[r_child]<data_[l_child]))
          min_idx = r_child;
      else
          min_idx = l_child;
      if(data_[curr]>data_[min_idx])
      {
        swaps_.push_back(make_pair(curr,min_idx));
        swap(data_, curr, min_idx);
        curr = min_idx;
        l_child = 2*curr + 1;
      }
      else
        break;
    }
  }
  void buildheap(vector<int>& data_)
  {
  int i,n=data_.size(),parent = (n-2)/2;
  for(i=parent;i>=0;i--)
  {
    sift_down(i,n-1,data_);
  }
  return;
  }

  void GenerateSwaps() {
    swaps_.clear();
    // The following naive implementation just sorts
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap,
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation
    // for (int i = 0; i < data_.size(); ++i)
    //   for (int j = i + 1; j < data_.size(); ++j) {
    //     if (data_[i] > data_[j]) {
    //       swap(data_[i], data_[j]);
    //       swaps_.push_back(make_pair(i, j));
    //     }
    //   }
    buildheap(data_);
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
