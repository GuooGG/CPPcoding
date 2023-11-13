/**
 * @file BinIndexedTree.cpp
 * @author GGo
 * @brief 树状数组
 * @version 0.1
 * @date 2023-11-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include<vector>

class BinIndexedTree{
public:
    
private:
    int lowbit(int x)
    {
        return x & -x;
    }
    void add(int x, int n){
        for(int i = x; i <= n; i += lowbit(i)){
            tree[i] += n;
        }
    }
    int query(int x){
        int ans = 0;
        for(int i = x; i > 0; i -= lowbit(i)){
            ans += tree[i];
        }
        return ans;
    }
    void update(int index, int val){
        add(index + 1, val);
        nums[index] = val;
    }
    BinIndexedTree(std::vector<int>& arr){
        this->nums = arr;
        n = arr.size();
        tree.resize(n + 1);
        for(int i = 0; i < n; i++){
            add(i + 1, nums[i]);
        }
    }
    std::vector<int> tree;
    std::vector<int> nums;
    int n = 0;
};