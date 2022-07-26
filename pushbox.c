#include <stdio.h>
#include <getch.h>
#include <stdlib.h>

int main(int argc,const char* argv[])
{
	int arr[8][8]={
		{0,0,2,2,2,2,0,0},
		{0,0,2,4,4,2,0,0},
		{0,2,2,0,4,2,2,0},
		{0,2,0,0,3,4,2,0},
		{2,2,0,3,0,0,2,2},
		{2,0,0,2,3,3,0,2},
		{2,0,0,1,0,0,0,2},
		{2,2,2,2,2,2,2,2}
	};
	int man_x = 6,man_y = 3,cnt = 0,num = 0;

	for(;;)
	{
		system("clear");
		for(int i=0; i<8; i++)
		{
			for(int j=0; j<8; j++)
			{
				if(0 == arr[i][j])
				{
					printf("  ");	
				}
				else if(1 == arr[i][j])
				{
					printf("@ ");	
				}
				else if(2 == arr[i][j])
				{
					printf("# ");	
				}
				else if(3 == arr[i][j])
				{
					printf("$ ");	
				}
				else if(4 == arr[i][j])
				{
					printf("O ");	
				}
				else if(5 == arr[i][j])
				{
					printf("@ ");	
				}
				else if(7 == arr[i][j])
				{
					printf("$ ");	
					num++;
				}
			}
			printf("\n");
		}
		if(4 == num)
		{
			printf("游戏结束，共用%d步",cnt);
			return 0;
		}
		num = 0;

		int ox = 0,oy = 0;
		switch(getch())
		{
			case 183:ox--;break;
			case 184:ox++;break;
			case 186:oy--;break;
			case 185:oy++;break;
		}

		if(0 == arr[man_x+ox][man_y+oy] || 4 == arr[man_x+ox][man_y+oy])
		{
			arr[man_x+ox][man_y+oy] += 1;
			arr[man_x][man_y] -= 1;
			man_x += ox;
			man_y += oy;
			cnt++;
			continue;
		}
		if(3 == arr[man_x+ox][man_y+oy] || 7 == arr[man_x+ox][man_y+oy])
		{
			if(0 == arr[man_x+ox*2][man_y+oy*2] || 4 == arr[man_x+ox*2][man_y+oy*2])
			{
				arr[man_x+ox*2][man_y+oy*2] += 3;
				arr[man_x+ox][man_y+oy] -= 2;
				arr[man_x][man_y] -= 1;
				man_x += ox;
				man_y += oy;
				cnt++;
			}
		}
	}
}
