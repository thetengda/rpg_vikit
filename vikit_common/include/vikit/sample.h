#ifndef VIKIT_SAMPLE_H_
#define VIKIT_SAMPLE_H_

#include <random>
#include <chrono>

namespace vk {

class Sample
{
public:
  static void setTimeBasedSeed();
  static int uniform(int from, int to);
  static double uniform();
  static double gaussian(double sigma);
  static std::ranlux24 gen_real;
  static std::mt19937 gen_int;
};

std::ranlux24 Sample::gen_real;
std::mt19937 Sample::gen_int;

inline void Sample::setTimeBasedSeed()
{
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  gen_real = std::ranlux24(seed);
  gen_int = std::mt19937(seed);
}

inline int Sample::uniform(int from, int to)
{
  std::uniform_int_distribution<int> distribution(from, to);
  return distribution(gen_int);
}

inline double Sample::uniform()
{
  std::uniform_real_distribution<double> distribution(0.0, 1.0);
  return distribution(gen_real);
}

inline double Sample::gaussian(double stddev)
{
  std::normal_distribution<double> distribution(0.0, stddev);
  return distribution(gen_real);
}

} // namespace vk

#endif // VIKIT_SAMPLE_H_
