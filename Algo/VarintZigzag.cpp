/**
 * @file VarintZigzag.cpp
 * @author GGo
 * @brief Varint编码与Zigag编码
 *          两者对于小数据的序列化十分有效，
 *          可以节省大量内存开销
 * @date 2023-11-06
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include<stdint.h>
#include<iostream>
#include<bitset>
using namespace std;

/// @brief Zigzag编码解码 
uint32_t encodeZigzag32(const int32_t& value){
    if(value < 0){
        return ((uint32_t)(-value) * 2 - 1);
    }else{
        return value * 2;
    }
}

uint64_t encodeZigzag64(const int64_t& value){
    if(value < 0){
        return ((uint64_t)(-value) * 2 - 1);
    }else{  
        return value * 2;
    }
}

int32_t decodeZigzag32(const uint32_t& value){
    return (value >> 1) ^ -(value & 1);
}

int64_t decodeZigzag64(const uint64_t& value){
    return (value >> 1) ^ -(value & 1);
}

void test_Zigzag(int32_t value){
    cout << "test01 start" << endl;
    cout << hex << "value= 0x" <<value << endl;
    cout << "value= " << std::bitset<32>(value) << endl;
    
    cout << "zigzag encoded value" << endl;
    uint32_t encodedValue  = encodeZigzag32(value);
    cout << hex << "value= 0x" << encodedValue << endl;
    cout << "value= " << std::bitset<32>(encodedValue) << endl;

    cout << "zigzag decoded value" << endl;
    int32_t decodedValue = decodeZigzag32(encodedValue);
    cout << hex << "value= 0x" << decodedValue << endl;
    cout << "value= " << std::bitset<32>(decodedValue) << endl;

    cout << "test01 end" << endl;
}

int main(){
    test_Zigzag(2);
    return 0;
}