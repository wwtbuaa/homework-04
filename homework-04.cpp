#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char StringInput[65][25];
int StringCount;
char OutputMatrix[100][100];
int StringLength[65];
int maxN;
int success; 
int StringPretreatment(int Temp)
{
	int Length = strlen(StringInput[Temp]);
	for (int i = 0;i < Length;i++)
	{
		if (StringInput[Temp][i] == ' ')
		{
			for (int j = i + 1;j < Length;j++)
				StringInput[Temp][j - 1] = StringInput[Temp][j];
			StringInput[Temp][Length - 1] = EOF;
			Length--;i--;
		}
	}
	return Length;
}
void StringSort()
{
	int i,j,k;
	char StringTemp[25];
	for (i = 0;i < StringCount - 1;i++)
		for (j = i + 1;j < StringCount;j++)
			if (StringLength[i] < StringLength[j])
			{
				k = StringLength[i];
				StringLength[i] = StringLength[j];
				StringLength[j] = k;
				strcpy(StringTemp,StringInput[i]);
				strcpy(StringInput[i],StringInput[j]);
				strcpy(StringInput[j],StringTemp);
			}
}
void PrintMatrix()
{
	int i,j;
	for (i = 0;i < maxN;i++)
	{
		for (j = 0;j < maxN - 1;j++)
			if (OutputMatrix[i][j] != ' ') printf("%c",OutputMatrix[i][j]);
			else printf("Q");
		if (OutputMatrix[i][maxN - 1] != ' ') printf("%c\n",OutputMatrix[i][maxN - 1]);
		else printf("Q\n");
	}
}
void FirstStep()
{
	int i,j;
	for (i = 0;i < maxN;i++)
		for (j = 0;j < maxN;j++) OutputMatrix[i][j] = ' ';
	for (i = 0;i < StringLength[0];i++)
		OutputMatrix[0][i] = StringInput[0][i];
	for (i = 0;i < StringLength[1];i++)
		OutputMatrix[maxN - 1][maxN - StringLength[1] + i] = StringInput[1][i];
	for (i = 0;i < StringLength[2];i++)
		OutputMatrix[maxN - StringLength[2] + i][0] = StringInput[2][i];
	for (i = 0;i < StringLength[3];i++)
		OutputMatrix[i][maxN - 1] = StringInput[3][i];
}
int StringJudge(int direct,int num,int x,int y)
{
	int i,flag = 0,res = 0;
	if (direct == 1)
	{
		if (y >= StringLength[num])
		{
			for (i = 0;i < StringLength[num];i++)
				if (OutputMatrix[x][y - i] != ' '
				&& OutputMatrix[x][y - i] != StringInput[num][i]) flag = 1;
			if (flag == 0) res = 1;
		}
	}
	if (direct == 2)
	{
		if (x >= StringLength[num])
		{
			for (i = 0;i < StringLength[num];i++)
				if (OutputMatrix[x - i][y] != ' '
				&& OutputMatrix[x - i][y] != StringInput[num][i]) flag = 1;
			if (flag == 0) res = 1;
		}
	}
	if (direct == 3)
	{
		if ((StringLength[num] + x) <= maxN && (StringLength[num] + y) <= maxN)
		{
			for (i = 0;i < StringLength[num];i++)
				if (OutputMatrix[x + i][y + i] != ' '
				&& OutputMatrix[x + i][y + i] != StringInput[num][i]) flag = 1;
			if (flag == 0) res = 1;
		}
	}
	if (direct == 4)
	{
		if (x >= StringLength[num] && y >= StringLength[num])
		{
			for (i = 0;i < StringLength[num];i++)
				if (OutputMatrix[x - i][y - i] != ' '
				&& OutputMatrix[x - i][y - i] != StringInput[num][i]) flag = 1;
			if (flag == 0) res = 1;
		}
	}
	if (direct == 5)
	{
		if (y >= StringLength[num] && (x + StringLength[num]) <= maxN)
		{
			for (i = 0;i < StringLength[num];i++)
				if (OutputMatrix[x + i][y - i] != ' '
				&& OutputMatrix[x + i][y - i] != StringInput[num][i]) flag = 1;
			if (flag == 0) res = 1;
		}
	}
	if (direct == 0)
	{
		if (x >= StringLength[num] && (y + StringLength[num]) <= maxN)
		{
			for (i = 0;i < StringLength[num];i++)
				if (OutputMatrix[x - i][y + i] != ' '
				&& OutputMatrix[x - i][y + i] != StringInput[num][i]) flag = 1;
			if (flag == 0) res = 1;
		}
	}
	return res;
}
void StringIntoMatrix(int direct,int num,int x,int y)
{
	success++;
	int i;
	if (direct == 1)
	{
		for (i = 0;i < StringLength[num];i++) OutputMatrix[x][y - i] = StringInput[num][i];
	}
	if (direct == 2)
	{
		for (i = 0;i < StringLength[num];i++) OutputMatrix[x - i][y] = StringInput[num][i];
	}
	if (direct == 3)
	{
		for (i = 0;i < StringLength[num];i++) OutputMatrix[x + i][y + i] = StringInput[num][i];
	}
	if (direct == 4)
	{
		for (i = 0;i < StringLength[num];i++) OutputMatrix[x - i][y - i] = StringInput[num][i];
	}
	if (direct == 5)
	{
		for (i = 0;i < StringLength[num];i++) OutputMatrix[x + i][y - i] = StringInput[num][i];
	}
	if (direct == 0)
	{
		for (i = 0;i < StringLength[num];i++) OutputMatrix[x - i][y + i] = StringInput[num][i];
	}
}
void MatrixProduce(int StringNum)
{
	int StringDirect = StringNum % 6;
	int i,j,flag = 0,suit;
	for (i = 0;i < maxN;i++)
	{
		for (j = 0;j < maxN;j++)
		{
			if (OutputMatrix[i][j] == ' ' || OutputMatrix[i][j] == StringInput[StringNum][0])
			{
				suit = StringJudge(StringDirect,StringNum,i,j);
				if (suit == 1)
				{
					StringIntoMatrix(StringDirect,StringNum,i,j);
					flag = 1;
				}
			}
			if (flag == 1) break;
		}
		if (flag == 1) break;
	}
}
int main()
{
	freopen("input5.txt","r",stdin);
	freopen("output5.txt","w",stdout);
	StringCount = 0;success = 4;
	while (gets(StringInput[StringCount]))
	{
		StringLength[StringCount] = StringPretreatment(StringCount);
		StringCount++;
	}
	StringSort();
	maxN = 13;
	FirstStep();
	for (int i = 4;i < StringCount;i++) MatrixProduce(i);
	PrintMatrix();
	printf("%d*%d\n",maxN,maxN);
	printf("%d %d\n",StringCount,success);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
