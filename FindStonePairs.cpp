#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>
using namespace std;



//用hashmap的方法，时间复杂度O(n)
std::vector<std::pair<int, int> > findStonePairs(const std::vector<float>& stones, float D) {
    std::unordered_map<float, int> map;
    for (int i = 0; i < stones.size(); ++i) {
        map[stones[i]] = i;
    }
    std::vector<std::pair<int, int> > StonePairs; // Initialize with (-1, -1) as default return value
    if(D==0){
        std::unordered_map<float, int> uniqueWights;
        for (int i = 0; i < stones.size(); ++i) {
            float weight = stones[i];
            if (uniqueWights.find(weight) != uniqueWights.end()) {
                StonePairs.push_back(std::make_pair(i, uniqueWights[weight]));
                std::cout << "Same weight stone pairs:" << "(" << i << ", " << uniqueWights[weight] << ")" << std::endl;
            } else {
                uniqueWights[weight] = i;
            }
        }
       return StonePairs;
    }


    
    // if (D==0){
    //     for (int i = 0; i < stones.size(); i++)
    //     {
    //         StonePairs.push_back(std::make_pair(i,i));
    //         std::cout << "Same weight stone pairs:" << "(" << i << ", " << i << ")" << std::endl;
    //     }
    //     return StonePairs;
    // }
    //i 从0开始，i++，i<stones.size()，i=0,1,2,3,4
    for (int i = 0; i < stones.size(); ++i) { 
        float target = stones[i] + D;
        if (map.find(target) != map.end()) {
            StonePairs.push_back(std::make_pair(i, map[target]));
        }
    }
    return StonePairs; //构建一个pair的vector，里面存放所有符合条件的pair   
}

// #include <iostream>
// #include <vector>
// #include <utility>
//用遍历的方法，时间复杂度O(n^2)
// std::pair<int, int> findStonePair(const std::vector<float>& stones, float D) {
//     int n = stones.size();
//     std::pair<int, int> stonePair(-1, -1);  // Initialize with (-1, -1) as default return value
    
//     for (int i = 0; i < n - 1; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (std::abs(stones[i] - stones[j]) == D) {
//                 stonePair.first = i;
//                 stonePair.second = j;
//                 return stonePair;  // Found a pair, return immediately
//             }
//         }
//     }
    
//     return stonePair;  // No pair found, return (-1, -1)
// }
using namespace std;
int main() {
    std::vector<float> stones;
    stones.push_back(1.22);
    stones.push_back(3.42);
    stones.push_back(3.42);
    // stones.push_back(5.62);
    // stones.push_back(7.82);
    // stones.push_back(9.02);
    float D = 0;
    

    if(stones.size() == 0){
            std::cout << "No stone found." << std::endl;
            return 0;
        }
        if(stones.size() == 1){
            std::cout << "Single stone input, the weight is " << std::endl;
            std::cout << "[" << stones[0] << "]" << std::endl;
            return 0;
        }
        if(stones.size() > 1){
            for(int i = 0; i < stones.size(); i++){
                if(stones[i] != stones[0]){
                    break;
                }
                if(i == stones.size() - 1){
                    std::cout << "Same weight stones input, the weight is" << std::endl;
                    std::cout << "[" << stones[0] << "]" << std::endl;
                    return 0;
                }
            }
        }
        //if the input D is 0,return same stones weight set

    std::vector<std::pair<int, int> > result = findStonePairs(stones, D);

    if (result.empty()) {
        std::cout << "No stone pairs found." << std::endl;
    } else {
        std::cout << "Stone pairs found:" << std::endl;

        if (result.size() == 1) {
            const std::pair<int, int>& pair = result[0];
            std::cout << "The only pair is:" << std::endl;
            std::cout << "(" << pair.first << ", " << pair.second << ")" << std::endl;
            return 0;
        }
        
        for (size_t i = 0; i < result.size(); ++i) {
            const std::pair<int, int>& pair = result[i];
            std::cout << "(" << pair.first << ", " << pair.second << ")" << std::endl;
        }
    }
 
    return 0;
    

}


