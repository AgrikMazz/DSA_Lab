#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct{
    float x;
    float y;
} Point;

typedef struct{
    Point* vertices;
    int numVertices;
} Polygon;

float orientation(Point p, Point q, Point r){
    return (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
}

bool onSegment(Point p, Point q, Point r){
    return (q.x <= fmax(p.x, r.x) && q.x >= fmin(p.x, r.x) && q.y <= fmax(p.y, r.y) && q.y >= fmin(p.y, r.y));
}

bool doLinesIntersect(Point p1, Point q1, Point p2, Point q2){
    float o1 = orientation(p1, q1, p2);
    float o2 = orientation(p1, q1, q2);
    float o3 = orientation(p2, q2, p1);
    float o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4) return true;

    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}

bool isPointInPolygon(Point point, Polygon poly){
    bool inside = false;
    for (int i = 0, j = poly.numVertices - 1; i < poly.numVertices; j = i++) {
        if (((poly.vertices[i].y > point.y) != (poly.vertices[j].y > point.y)) && (point.x < (poly.vertices[j].x - poly.vertices[i].x) * (point.y - poly.vertices[i].y) /(poly.vertices[j].y - poly.vertices[i].y) + poly.vertices[i].x)){
            inside = !inside;
        }
    }
    return inside;
}

bool doPolygonsIntersect(Polygon poly1, Polygon poly2){
    int i, j;
    
    for (i = 0; i < poly1.numVertices; i++) {
        if (isPointInPolygon(poly1.vertices[i], poly2)) return true;
    }
    
    for (i = 0; i < poly2.numVertices; i++) {
        if (isPointInPolygon(poly2.vertices[i], poly1)) return true;
    }

    for (i = 0; i < poly1.numVertices; i++) {
        for (j = 0; j < poly2.numVertices; j++) {
            Point p1 = poly1.vertices[i];
            Point q1 = poly1.vertices[(i + 1) % poly1.numVertices];
            Point p2 = poly2.vertices[j];
            Point q2 = poly2.vertices[(j + 1) % poly2.numVertices];
            
            if (doLinesIntersect(p1, q1, p2, q2)) return true;
        }
    }
    
    return false;
}

int main(){
    int n1, n2;
    
    printf("Enter number of vertices for first polygon: ");
    scanf("%d", &n1);
    
    Polygon poly1;
    poly1.numVertices = n1;
    poly1.vertices = (Point*)malloc(n1 * sizeof(Point));
    
    printf("Enter coordinates for first polygon:\n");
    for (int i = 0; i < n1; i++){
        printf("Vertex %d (x y): ", i + 1);
        scanf("%f %f", &poly1.vertices[i].x, &poly1.vertices[i].y);
    }
    
    printf("Enter number of vertices for second polygon: ");
    scanf("%d", &n2);
    
    Polygon poly2;
    poly2.numVertices = n2;
    poly2.vertices = (Point*)malloc(n2 * sizeof(Point));
    
    printf("Enter coordinates for second polygon:\n");
    for (int i = 0; i < n2; i++){
        printf("Vertex %d (x y): ", i + 1);
        scanf("%f %f", &poly2.vertices[i].x, &poly2.vertices[i].y);
    }
    
    if (doPolygonsIntersect(poly1, poly2)){
        printf("The polygons intersect.\n");
    } 
    else{
        printf("The polygons do not intersect.\n");
    }
       
    return 0;
}