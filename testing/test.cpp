#include <experimental/filesystem>


using namespace std;

namespace fs = experimental::filesystem;

int main()
{
  auto path = fs::current_path();
  return 0;
}  // namespace )