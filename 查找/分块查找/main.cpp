#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

//索引表
typedef struct {
    ElemType   maxValue; //最大关键字
    int low,high;  //块的区间范围
}Index;

ElemType List[100];//顺序表存储实际元素