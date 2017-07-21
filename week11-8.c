#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

struct Point
{
    int x, y;
};

int compareX(const void* a, const void* b)
{
    struct Point *p1 = (struct Point *)a; struct Point *p2 = (struct Point *)b;
    return (p1->x - p2->x);
}

int compareY(const void* a, const void* b)
{
    struct Point *p1 = (struct Point *)a,   *p2 = (struct Point *)b;
    return (p1->y - p2->y);
}
 

float dist(struct Point p1, struct Point p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y)
               );
}
 

float bruteForce(struct Point P[], int n)
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}
 

float min(float x, float y)
{
    return (x < y)? x : y;
}
 
 

float stripClosest(struct Point strip[], int size, float d)
{
    float min = d;
 
    
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i],strip[j]) < min)
                min = dist(strip[i], strip[j]);
 
    return min;
}
 

float closestUtil(struct Point Px[], struct Point Py[], int n)
{
    
    if (n <= 3)
        return bruteForce(Px, n);
 
    int mid = n/2;
    struct Point midPoint = Px[mid];
 
    struct Point Pyl[mid+1];  
    struct Point Pyr[n-mid-1];  
    int li = 0, ri = 0;
    for (int i = 0; i < n; i++)
    {
      if (Py[i].x <= midPoint.x)
         Pyl[li++] = Py[i];
      else
         Pyr[ri++] = Py[i];
    }
 
    float dl = closestUtil(Px, Pyl, mid);
    float dr = closestUtil(Px + mid, Pyr, n-mid);
 
    float d = min(dl, dr);
 
    struct Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(Py[i].x - midPoint.x) < d)
            strip[j] = Py[i], j++;
 
    return min(d, stripClosest(strip, j, d) );
}
 
float closest(struct Point P[], int n)
{
    struct Point Px[n];
    struct Point Py[n];
    for (int i = 0; i < n; i++)
    {
        Px[i] = P[i];
        Py[i] = P[i];
    }
 
    qsort(Px, n, sizeof(struct Point), compareX);
    qsort(Py, n, sizeof(struct Point), compareY);
 
    
    return closestUtil(Px, Py, n);
}
 
int main()
{
    struct Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    printf("The smallest distance is %f",closest(P, n));
    return 0;
}