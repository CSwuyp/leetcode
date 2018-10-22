#include <iostream>
#include <iomanip>
using namespace std;
 
//signed
typedef signed char        int8;
typedef short              int16;
typedef int                int32;
typedef long long          int64;
//unsigned
typedef unsigned char      uint8;
typedef unsigned short     uint16;
typedef unsigned int       uint32;
typedef unsigned long long uint64;
 
#pragma pack(push)
#pragma pack(1)//单字节对齐
typedef struct{
    uint32 ID;
    uint32 Num;
    uint32 Type;
    uint32 lat;
    uint32 lng;
    uint32 alt;
    uint32 speed;
}Waypoint;//Payload_Data
 
#pragma pack(pop)
 
 
 
 
void EndianSwap(uint8 *pData, int startIndex, int length);
 
 
 
int main()
{
 
    Waypoint wp,wp_ori;
    int len = sizeof(Waypoint);
    cout << "size of Waypoint: " << len << endl;
 
    wp.ID    = 0x00000011;
    wp.Num   = 0x00002200;
    wp.Type  = 0xDD0CB0AA;
    wp.lat   = 0x00330000;
    wp.lng   = 0x44000000;
    wp.alt   = 0xABCD1234;
    wp.speed = 0x12345678;
 
    wp_ori = wp;
 
 
    int i = 0;
    uint8* pData = (uint8*)(&wp);
    for (i = 0; i < len; i += 4)
    {
        EndianSwap(pData,i,4);
    }
 
 
    cout << endl;
    cout << uppercase << hex << "改变字节序前: 0x" << setfill('0') << setw(8) << wp_ori.ID << endl;
    cout << uppercase << hex << "改变字节序后: 0x" <<setfill('0') << setw(8) << wp.ID <<endl;
    cout << endl;
    cout << uppercase << hex << "改变字节序前: 0x" << setfill('0') << setw(8) << wp_ori.Num << endl;
    cout << uppercase << hex << "改变字节序后: 0x" << setfill('0') << setw(8) << wp.Num << endl;
    cout << endl;
    cout << uppercase << hex << "改变字节序前: 0x" << setfill('0') << setw(8) << wp_ori.Type << endl;
    cout << uppercase << hex << "改变字节序后: 0x" << setfill('0') << setw(8) << wp.Type << endl;
    cout << endl;
    cout << uppercase << hex << "改变字节序前: 0x" << setfill('0') << setw(8) << wp_ori.lat << endl;
    cout << uppercase << hex << "改变字节序后: 0x" << setfill('0') << setw(8) << wp.lat << endl;
    cout << endl;
    cout << uppercase << hex << "改变字节序前: 0x" << setfill('0') << setw(8) << wp_ori.lng << endl;
    cout << uppercase << hex << "改变字节序后: 0x" << setfill('0') << setw(8) << wp.lng << endl;
    cout << endl;
    cout << uppercase << hex << "改变字节序前: 0x" << setfill('0') << setw(8) << wp_ori.alt << endl;
    cout << uppercase << hex << "改变字节序后: 0x" << setfill('0') << setw(8) << wp.alt << endl;
    cout << endl;
    cout << uppercase << hex << "改变字节序前: 0x" << setfill('0') << setw(8) << wp_ori.speed << endl;
    cout << uppercase << hex << "改变字节序后: 0x" << setfill('0') << setw(8) << wp.speed << endl;
    return 0;
}
 
void EndianSwap(uint8 *pData, int startIndex, int length)
{
    int i,cnt,end,start;
    cnt = length / 2;
    start = startIndex;
    end  = startIndex + length - 1;
    uint8 tmp;
    for (i = 0; i < cnt; i++)
    {
        tmp            = pData[start+i];
        pData[start+i] = pData[end-i];
        pData[end-i]   = tmp;
    }
}
