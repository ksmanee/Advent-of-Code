
// #include <iostream>
// #include <math.h>
// #include <string>
// #include <vector>
// #include <fstream>
// using namespace std;

// class Part1
// {
//     public:
//         void riskLevel(vector<vector<int>> heightMap);
// };

// class Part2
// {
//     public:
//         void basinSize(vector<vector<int>> heightMap);
// };
// int main()
// {
//     //actual inputfile
//     ifstream file("inputDay9.txt");
//     //used to get size of line
//     ifstream lineSize("inputDay9.txt");

//     string line;
//     string num;
//     vector<int> lineHeightMap;
//     vector<vector<int>> heightMap;

//     getline(lineSize, line);
//     for (int i = 0; i < line.size()+2; i++)
//     {
//         lineHeightMap.push_back(9);
//     }
//     heightMap.push_back(lineHeightMap);
//     lineHeightMap.clear();
//     lineSize.close();

//     while(getline(file, line))
//     {
//         lineHeightMap.push_back(9);
//         for (int i = 0; i < line.size(); i++)
//         {
//             num = line[i];
//             lineHeightMap.push_back(stoi(num));
//         }
//         lineHeightMap.push_back(9);
//         heightMap.push_back(lineHeightMap);
//         lineHeightMap.clear();
//     }
//     for (int i = 0; i < line.size()+2; i++)
//     {
//         lineHeightMap.push_back(9);
//     }
//     heightMap.push_back(lineHeightMap);
//     file.close();

//     for (int i = 0; i < heightMap.size(); i++)
//     {
//         for (int j = 0; j < heightMap[0].size(); j++)
//         {
//             cout << heightMap[i][j];
//         }
//         cout << endl;
//     }
//     for (int i = 0; i < heightMap.size(); i++)
//     {
//         cout << i;
//         for (int j = 0; j < heightMap[0].size(); j++)
//         {
//             cout << j;
//         }
//         cout << endl;
//     }
    

//     Part1 solution1;
//     Part2 solution2;

//     solution1.riskLevel(heightMap);
//     solution2.basinSize(heightMap);
//     return 0;
// }

// void Part1::riskLevel(vector<vector<int>> heightMap)
// {
//     int colSize = heightMap[0].size();
//     int rowSize = heightMap.size();
//     vector<int> lowPoint;
//     int i, j;
//     int risk = 0;

//     for (i = 0; i < rowSize; i++)
//     {
//         for (j = 0; j < colSize; j++)
//         {
//             if (j > 0 && i > 0 && i < rowSize-1 && j < colSize-1)
//             {
//                 //check middle of heightmap
//                 if ((heightMap[i][j] < heightMap[i+1][j]) && (heightMap[i][j] < heightMap[i][j+1]) && (heightMap[i][j] < heightMap[i-1][j]) && (heightMap[i][j] < heightMap[i][j-1]))
//                 {
//                     lowPoint.push_back(heightMap[i][j]);
//                 }
//             }
//         }
//     }


//     //calculate risklevel
//     for (i = 0; i < lowPoint.size(); i++)
//     {
//         risk += (1 + lowPoint[i]);
//     }
//     cout << "Risk level is: " << risk << endl;
// }

// void Part2::basinSize(vector<vector<int>> heightMap)
// {
//     int colSize = heightMap[0].size();
//     int rowSize = heightMap.size();
//     vector<int> lowPoint;
//     vector<int> basin;
//     int i, j;
//     int k, l;
//     int size = 0;

//     for (i = 0; i < rowSize; i++)
//     {
//         for (j = 0; j < colSize; j++)
//         {
//             if (j > 0 && i > 0 && i < rowSize-1 && j < colSize-1)
//             {
//                 //check middle of heightmap
//                 if ((heightMap[i][j] < heightMap[i+1][j]) && (heightMap[i][j] < heightMap[i][j+1]) && (heightMap[i][j] < heightMap[i-1][j]) && (heightMap[i][j] < heightMap[i][j-1]))
//                 {
//                     k = i;
//                     l = j;

//                     // check up-right
//                     while (heightMap[k][l] != 9)
//                     {
//                         if (heightMap[k][l] != 9)
//                             size++;
//                         k++;
//                         l++;
//                     }
//                     k = i;
//                     l = j;

//                     //check down-left
//                     while (heightMap[k][l] != 9 && k > 0 && l > 0)
//                     {
//                         if (heightMap[k][l] != 9)
//                             size++;
//                         k--;
//                         l--;
//                     }
//                     k = i;
//                     l = j;

//                     //check up left 
//                     while (heightMap[k][l] != 9 && k > 0 && l > 0)
//                     {
//                         if (heightMap[k][l] != 9)
//                             size++;
//                         k++;
//                         l--;
//                     }
//                     k = i;
//                     l = j;

//                     //check down-right
//                     while (heightMap[k][l] != 9 && k > 0 && l > 0)
//                     {
//                         if (heightMap[k][l] != 9)
//                             size++;
//                         k--;
//                         l--;
//                     }
//                     k = i;
//                     k = j;
//                     // while(heightMap[k][l] != 9)
//                     // {
//                     //     k++;
//                     //     while(heightMap[k][l] != 9)                    
//                     //     {
//                     //         l++;
//                     //         size++;
//                     //     }
//                     //     l = j;
//                     //     while (heightMap[k][l] != 9)
//                     //     {
//                     //         l--;
//                     //         size++;
//                     //     }
//                     // }
//                     // k = i;
//                     // l = j;
//                     // while(heightMap[k][l] != 9)
//                     // {
//                     //     k--;
//                     //     while(heightMap[k][l] != 9)                    
//                     //     {
//                     //         l++;
//                     //         size++;
//                     //     }
//                     //     l = j;
//                     //     while (heightMap[k][l] != 9)
//                     //     {
//                     //         l--;
//                     //         size++;
//                     //     }
//                     // }
//                     basin.push_back(size);
//                 }
//                 size = 0;
//             }
//         }
//     }
//     //calculate risklevel
//     for (int i = 0; i < basin.size(); i++)
//     {
//         cout << basin[i] << endl;
//     }
    

/*

    idea_land:
      -> part 1: straight-forward linear scan while being mindful of edge cases
      -> part 2: spiral back-tracking search of strictly increasing paths
        >> can be done via DFS traversals on all directionals using our
       low points as start positions
          >> we perform a search of every directional and continue so long as the direction
          leads to a strictly increasing height
        >> since heights of value 9 do not count as being in a basin, we can use it as means
        of flagging visited heights
        >> basically a connected-components traversal

*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

auto isValidMatrixPosition(const std::vector<std::vector<std::uint32_t>>& matrix, std::size_t i, std::size_t j) -> bool
{
  return (i >= 0 && i < matrix.size() && j >= 0 && j < matrix[i].size());
}

auto dfs(
  std::vector<std::vector<std::uint32_t>>& heightMap,
  std::vector<std::uint32_t>& basin,
  std::size_t i, std::size_t j, std::uint32_t maxHeight
    ) -> void
{
  auto height = heightMap[i][j];
  heightMap[i][j] = maxHeight;
  if (height < maxHeight)
  {
    basin.push_back(height);
    // search up
    if (isValidMatrixPosition(heightMap, i - 1, j) && heightMap[i - 1][j] > height)
    {
      dfs(heightMap, basin, i - 1, j, maxHeight);
    }
    // search right
    if (isValidMatrixPosition(heightMap, i, j + 1) && heightMap[i][j + 1] > height)
    {
      dfs(heightMap, basin, i, j + 1, maxHeight);
    }
    // search down
    if (isValidMatrixPosition(heightMap, i + 1, j) && heightMap[i + 1][j] > height)
    {
      dfs(heightMap, basin, i + 1, j, maxHeight);
    }
    // search left
    if (isValidMatrixPosition(heightMap, i, j - 1) && heightMap[i][j - 1] > height)
    {
      dfs(heightMap, basin, i, j - 1, maxHeight);
    }
  }
}

auto findAndSortBasins(std::vector<std::vector<uint32_t>>& heightMap, const std::vector<std::pair<std::size_t, std::size_t>>& lowPoints) -> std::vector<std::vector<uint32_t>>
{
  auto basins = std::vector<std::vector<std::uint32_t>>{};
  auto maxHeight = uint32_t{9};
  for (auto& lowPoint : lowPoints)
  {
    auto i = lowPoint.first;
    auto j = lowPoint.second;
    if (heightMap[i][j] < maxHeight)
    {
      auto basin = std::vector<std::uint32_t>{};
      dfs(heightMap,  basin, i, j, maxHeight);
      basins.push_back(std::move(basin));
    }
  }
  auto sortBasinsBySizeAsc = [](const std::vector<std::uint32_t>& lhs, const std::vector<uint32_t>& rhs)
  {
    return lhs.size() >= rhs.size();
  };
  std::sort(std::begin(basins), std::end(basins), sortBasinsBySizeAsc);
  return basins;
}

auto findHeightMapLowPoints(const std::vector<std::vector<std::uint32_t>>& heightMap) -> std::vector<std::pair<std::size_t, std::size_t>>
{
  auto lowPoints = std::vector<std::pair<std::size_t, std::size_t>>{};
  for (std::size_t i = 0; i < heightMap.size(); ++i)
  {
    for (std::size_t j = 0; j < heightMap.size(); ++j)
    {
      auto height = heightMap[i][j];
      bool isLowPoint {true};
      // look up
      if (isValidMatrixPosition(heightMap, i - 1, j) && heightMap[i - 1][j] <= height)
      {
        isLowPoint = false;
      }
      // look down
      if (isValidMatrixPosition(heightMap, i + 1, j) && heightMap[i + 1][j] <= height)
      {
        isLowPoint = false;
      }
      // look left
      if (isValidMatrixPosition(heightMap, i, j - 1) && heightMap[i][j - 1] <= height)
      {
        isLowPoint = false;
      }
      // look right
      if (isValidMatrixPosition(heightMap, i, j + 1) && heightMap[i][j + 1] <= height)
      {
        isLowPoint = false;
      }
      // press a + start
      if (isLowPoint)
      {
        lowPoints.push_back({i, j});
      }
    }
  }
  return lowPoints;
}

auto solvePuzzle(const std::string& inputFileName) ->void
{
  auto ifs = std::ifstream{inputFileName};
  if (!ifs.is_open())
  {
    std::cerr << "ERROR::solvePuzzle(const std::string&)::FAILED_TO_OPEN_FILE: {" << inputFileName << "}" << std::endl;
    return;
  }
  auto heightMap = std::vector<std::vector<std::uint32_t>>{};
  auto line = std::string{""};
  while (std::getline(ifs, line))
  {
    auto heights = std::vector<std::uint32_t>{};
    for (const auto& height : line)
    {
      heights.push_back(std::move(height - '0'));
    }
    heightMap.push_back(std::move(heights));
  }
  std::cout << "---part 1---" << std::endl;
  auto lowPoints = findHeightMapLowPoints(heightMap);
  std::cout << "calculating risk factor" << std::endl;
  auto riskFactor = std::uint32_t{0};
  for (const auto& lowPoint : lowPoints)
  {
    auto i = lowPoint.first;
    auto j = lowPoint.second;
    riskFactor += (heightMap[i][j] + 1);
  }
  std::cout << "soln: " << riskFactor << std::endl;
  std::cout << "---part 2---" << std::endl;
  auto basins = findAndSortBasins(heightMap, lowPoints);
  auto basinSize = std::uint32_t{1};
  std::cout << "first three largest basins" << std::endl;
  for (std::size_t count = 0; count < 3; ++count)
  {
    auto basin = basins[count];
    std::cout << "basin: { ";
    for (const auto& n : basin)
    {
      std::cout << n << ' ';
    }
    std::cout << '}' << ", size: " << basin.size() << std::endl;
    basinSize *= basin.size();
  }
  std::cout << "soln: " << basinSize << std::endl;
}
auto main(void) -> int
{
  //solvePuzzle("example-input.txt");
  solvePuzzle("inputDay9.txt");
  return 0;
}