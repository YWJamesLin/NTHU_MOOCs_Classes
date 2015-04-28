#include <stdio.h>

struct t_point
{
	int x;
	int y;
};
typedef struct t_point Point;
struct t_rect
{
	struct t_point pt1;
	struct t_point pt2;
};
typedef struct t_rect Rect;

int area(Rect *);

int main(void)
{
	Rect rect1={{10, 20}, {50, 60}};
	Rect rect2=rect1;
	Rect rect_array[100];

	printf("pt1.x=%d, pt1.y=%d\n", rect2.pt1.x, rect2.pt1.y);
	printf("pt2.x=%d, pt2.y=%d\n", rect2.pt2.x, rect2.pt2.y);
	printf("area = %d\n", area(&rect2));
	
	return 0;
}

int area(Rect *rect)
{
	return (rect->pt1.x-rect->pt2.x)*(rect->pt1.y-rect->pt2.y);
}
