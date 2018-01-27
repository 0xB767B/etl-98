#define NDEBUG

#include <assert.h>

template<typename T, int N>
class Array
{
public:
  int elements[N];

  T& operator[](int i) {
      RangeCheck(i);
      return elements[i];
  }
private:
  void RangeCheck(int i) {
      assert(i < N);
  }
};

int main()
{
  Array<int, 5> a = {0, 1, 2, 3, 1 };

  int sum = 0;
  for(int i = 0; i < 5; i++) {
      sum += a[i];
  }

  return sum;
}
