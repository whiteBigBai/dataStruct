#include <stdio.h>
#include <stdlib.h>

typedef int ELemType;

typedef struct {
    ELemType *elem;
    int TableLen;
}SSTable;


//折半查找(升序排列)
int Binary_Search(SSTable L,ELemType key){
    int low=0,high=L.TableLen-1,mid;
    while(low<=high){
        mid=(low+high)/2; //取中间位置
        if(L.elem[mid]==key)
            return mid; //查找成功则返回所在位置
        else if(L.elem[mid]>key)
            high=mid-1;//从前半部分继续查找
        else 
            low=mid+1;//从后半部分继续查找
    }
    return -1; //查找失败，返回-1
}


