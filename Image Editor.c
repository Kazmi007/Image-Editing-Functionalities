#include <stdio.h>
#define size 25

int abs(int num)
{
    if (num < 0)
        return -num;
    else    
        return num;
}

void fill(int arr[size][size], int fc, int y, int x, int tc)
{
    if ((y>-1 && y<size) && (x>-1 && x<size))
    {
        arr[y][x] = fc;
        if (arr[y-1][x-1] == tc)
            fill(arr, fc, y-1, x-1, tc);
        if (arr[y-1][x] == tc)
            fill(arr, fc, y-1, x, tc);
        if (arr[y-1][x+1] == tc)
            fill(arr, fc, y-1, x+1, tc);
        if (arr[y][x+1] == tc)
            fill(arr, fc, y, x+1, tc);
        if (arr[y+1][x+1] == tc)
            fill(arr, fc, y+1, x+1, tc);
        if (arr[y+1][x] == tc)
            fill(arr, fc, y+1, x, tc);
        if (arr[y+1][x-1] == tc)
            fill(arr, fc, y+1, x-1, tc);
        if (arr[y][x-1] == tc)
            fill(arr, fc, y, x-1, tc);
    }
}
    
int main()
{   
    int i, j, c, cy, cx, fy, fx, img[size][size];
    int y, x, y1, x1, py, px, py1, px1, w, l, count=0, deg;
    float oy, ox, opy, opx, ty, tx, temp;
    char op, dir;
    for (i=0; i<size; i++)
        for (j=0; j<size; j++)
                scanf(" %d", &img[i][j]);
    scanf(" %c", &op);
    if (op == 'F')
    {
        scanf(" %d %d", &cy, &cx);
        scanf(" %d %d", &fy, &fx);
        if (cy<0 && cx<0)
            c = 0;
        else if (cy<0 && (cx>=0 && cx<size))
            c = 1;
        else if (cy<0 && cx>=size)
            c = 2;
        else if ((cy>=0 && cy<size) && cx>=size)
            c = 3;
        else if (cy>=size && cx>=size)
            c = 4;
        else if (cy>=size && (cx>=0 && cx<size))
            c = 5;
        else if (cy>=size && cx<0)
            c = 6;
        else if ((cy>=0 && cy<size) && cx<0)
            c = 7;
        else
            c = img[cy][cx];
        if (img[fy][fx] != c)
            fill(img, c, fy, fx, img[fy][fx]);
        for (i=0; i<size; i++)
        {
            for (j=0; j<size; j++)
                printf("%d ", img[i][j]);
            printf("\n");
        }
    }
    else if (op == 'P')
    {
        scanf(" %d %d %d %d", &y, &x, &y1, &x1);
        scanf(" %d %d %d %d", &py, &px, &py1, &px1);
        w = abs(y - y1);
        l = abs(x - x1);
        if (y > y1)
        {   
            y = y1;
            if (x > x1)
                    x = x1;
        }
        else 
            if (x > x1)
                    x = x1; 
        if (py > py1)
        {   
            py = py1;
            if (px > px1)
                    px = px1;
        }
        else 
            if (px > px1)
                    px = px1; 
        for (i=0; i<(w+1); i++)
            for (j=0; j<(l+1); j++)
            {
                if (img[py+i][px+j] != img[y+i][x+j])
                {
                    img[py+i][px+j] = img[y+i][x+j];
                    count += 1;
                }
            }
        for (i=0; i<size; i++)
        {
            for (j=0; j<size; j++)
                printf("%d ", img[i][j]);
            printf("\n");
        }
        printf("%d\n", count);
    }
    else if (op == 'R')
    {
        scanf(" %c %d", &dir, &deg);
        scanf(" %d %d %d %d", &y, &x, &y1, &x1);
        scanf(" %d %d %d %d", &py, &px, &py1, &px1);
        w = abs(y - y1);
        l = abs(x - x1);
        oy =  y + ((float)w / 2);
        ox =  x + ((float)l / 2);
        opy = py + ((float)w / 2);
        opx = px + ((float)l / 2);
        for (i=0; i<(w+1); i++)
            for (j=0; j<(l+1); j++)
            {
                ty = (y + i) - oy;
                tx = (x + j) - ox;
                if ((dir=='R' && deg==270) || (dir=='L' && deg==90))
                {
                    temp = ty;
                    ty = -tx;
                    tx = temp;
                    if (img[(int)(opy+ty)][(int)(opx+tx)] != img[y+i][x+j])
                    {
                        img[(int)(opy+ty)][(int)(opx+tx)] = img[y+i][x+j];
                        count += 1;
                    }
                }  
                else if ((dir=='R' && deg==90) || (dir=='L' && deg==270))
                {
                    temp = ty;
                    ty = tx;
                    tx = -temp;
                    if (img[(int)(opy+ty)][(int)(opx+tx)] != img[y+i][x+j])
                    {
                        img[(int)(opy+ty)][(int)(opx+tx)] = img[y+i][x+j];
                        count += 1;
                    }
                }    
                else if (deg == 90)
                {
                    ty = -ty;
                    tx = -tx;
                    if (img[(int)(opy+ty)][(int)(opx+tx)] != img[y+i][x+j])
                    {
                        img[(int)(opy+ty)][(int)(opx+tx)] = img[y+i][x+j];
                        count += 1;
                    }
                }
                else 
                {
                    if (img[py+i][px+j] != img[y+i][x+j])
                    {
                        img[py+i][px+j] = img[y+i][x+j];
                        count += 1;
                    }
                }
                               
            }
        for (i=0; i<size; i++)
        {
            for (j=0; j<size; j++)
                printf("%d ", img[i][j]);
            printf("\n");
        }
        printf("%d\n", count);   
    }
    return 0;
}