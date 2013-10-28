#include<stdio.h>
#include<string.h>

char s[51][51]; //传进来的字母矩阵
int  visit[22][22]; 
int number=27; //需要放进去的单词数目
char verbal[60][21];  //需要放进去的单词
int lenth[60];  //需要放进去的单词的长度
int position[3][60]; //需要放进去的单词的匹配位置和方向
int d1,d2,d3,d4,d5,d6,d7,d8,d9; 
int m=13,n=13; //矩阵大小
int check_verbal[60]; //单词在s中出现的次数
char result[105][105];

int search_1(int i,int j,int k)
{
	int temp=0;
	int starti=i,startj=j;
	while(i>0&&j>0&&i<=m&&j<=n&&temp<lenth[k]){
		if(s[i][j]==verbal[k][temp]){
			j++;
			temp++;
		}
		else
			return 0;
	}
	if(temp==lenth[k]){
		for(i=0;i<lenth[k];i++)
			visit[starti][startj+i]=1;
		check_verbal[k]++;
		position[0][k]=starti;
		position[1][k]=startj;
		position[2][k]=1;
		return 1;
	}
	else
		return 0;
}

int search_2(int i,int j,int k)
{
	int temp=0;
	int starti=i,startj=j;
	while(i>0&&j>0&&i<=m&&j<=n&&temp<lenth[k]){
		if(s[i][j]==verbal[k][temp]){
			i++;
			j++;
			temp++;
		}
		else
			return 0;
	}
	if(temp==lenth[k]){
		for(i=0;i<lenth[k];i++)
			visit[starti+i][startj+i]=1;
		check_verbal[k]++;
		position[0][k]=starti;
		position[1][k]=startj;
		position[2][k]=2;
		return 1;
	}
	else
		return 0;
}

int search_3(int i,int j,int k)
{
	int temp=0;
	int starti=i,startj=j;
	while(i>0&&j>0&&i<=m&&j<=n&&temp<lenth[k]){
		if(s[i][j]==verbal[k][temp]){
			i++;
			temp++;
		}
		else
			return 0;
	}
	if(temp==lenth[k]){
		for(i=0;i<lenth[k];i++)
			visit[starti+i][startj]=1;
		check_verbal[k]++;
		position[0][k]=starti;
		position[1][k]=startj;
		position[2][k]=3;
		return 1;
	}
	else
		return 0;
}

int search_4(int i,int j,int k)
{
	int temp=0;
	int starti=i,startj=j;
	while(i>0&&j>0&&i<=m&&j<=n&&temp<lenth[k]){
		if(s[i][j]==verbal[k][temp]){
			i++;
			j--;
			temp++;
		}
		else
			return 0;
	}
	if(temp==lenth[k]){
		for(i=0;i<lenth[k];i++)
			visit[starti+i][startj-i]=1;
		check_verbal[k]++;
		position[0][k]=starti;
		position[1][k]=startj;
		position[2][k]=4;
		return 1;
	}
	else
		return 0;
}

int search_5(int i,int j,int k)
{
	int temp=0;
	int starti=i,startj=j;
	while(i>0&&j>0&&i<=m&&j<=n&&temp<lenth[k]){
		if(s[i][j]==verbal[k][temp]){
			j--;
			temp++;
		}
		else
			return 0;
	}
	if(temp==lenth[k]){
		for(i=0;i<lenth[k];i++)
			visit[starti][startj-i]=1;
		check_verbal[k]++;
		position[0][k]=starti;
		position[1][k]=startj;
		position[2][k]=5;
		return 1;
	}
	else
		return 0;
}

int search_6(int i,int j,int k)
{
	int temp=0;
	int starti=i,startj=j;
	while(i>0&&j>0&&i<=m&&j<=n&&temp<lenth[k]){
		if(s[i][j]==verbal[k][temp]){
			i--;
			j--;
			temp++;
		}
		else
			return 0;
	}
	if(temp==lenth[k]){
		for(i=0;i<lenth[k];i++)
			visit[starti-i][startj-i]=1;
		check_verbal[k]++;
		position[0][k]=starti;
		position[1][k]=startj;
		position[2][k]=6;
		return 1;
	}
	else
		return 0;
}

int search_7(int i,int j,int k)
{
	int temp=0;
	int starti=i,startj=j;
	while(i>0&&j>0&&i<=m&&j<=n&&temp<lenth[k]){
		if(s[i][j]==verbal[k][temp]){
			i--;
			temp++;
		}
		else
			return 0;
	}
	if(temp==lenth[k]){
		for(i=0;i<lenth[k];i++)
			visit[starti-i][startj]=1;
		check_verbal[k]++;
		position[0][k]=starti;
		position[1][k]=startj;
		position[2][k]=7;
		return 1;
	}
	else
		return 0;
}

int search_8(int i,int j,int k)
{
	int temp=0;
	int starti=i,startj=j;
	while(i>0&&j>0&&i<=m&&j<=n&&temp<lenth[k]){
		if(s[i][j]==verbal[k][temp]){
			i--;
			j++;
			temp++;
		}
		else
			return 0;
	}
	if(temp==lenth[k]){
		for(i=0;i<lenth[k];i++)
			visit[starti-i][startj+i]=1;
		check_verbal[k]++;
		position[0][k]=starti;
		position[1][k]=startj;
		position[2][k]=8;
		return 1;
	}
	else
		return 0;
}

int check()
{
	int i,j;
	int temp;
	for(i=0;i<number;i++){
		if(check_verbal[i]!=1){
			printf("1");
			return 0;
		}
	}
	if(d1<=2&&d2<=2&&d3<=2&&d4<=2&&d5<=2&&d6<=2&&d7<=2&&d8<=2){
		printf("2");
		return 0;
	}
	for(i=1;i<=m;i++){
		temp=0;
		for(j=1;j<=n;j++)
			temp+=visit[i][j];
		if(temp==0){
			printf("3");
			return 0;
		}
	}
	for(j=1;j<=n;j++){
		temp=0;
		for(i=1;i<=m;i++)
			temp+=visit[i][j];
		if(temp==0){
			printf("4");
			return 0;
		}
	}
	temp=visit[1][1]+visit[1][n]+visit[n][1]+visit[n][n];
	if(temp==0)
		return 0;
	return 1;
}

int main()
{
	int x,y,check_value;
	int i,j,k;
	freopen("output5.txt","r",stdin);
	//scanf("%d",&n);
	for(i=1;i<=m;i++)
		gets(s[i]);
	fclose(stdin);
	freopen("input5.txt","r",stdin);
	for(i=0;i<number;i++){
		gets(verbal[i]);
		lenth[i]=strlen(verbal[i]);
	}
	for(k=0;k<number;k++){
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++){
				if(s[i][j]==verbal[k][0]){
					if(search_1(i,j,k)==1)
						d1++;
					if(search_2(i,j,k)==1)
						d2++;
					if(search_3(i,j,k)==1)
						d3++;
					if(search_4(i,j,k)==1)
						d4++;
					if(search_5(i,j,k)==1)
						d5++;
					if(search_6(i,j,k)==1)
						d6++;
					if(search_7(i,j,k)==1)
						d7++;
					if(search_8(i,j,k)==1)
						d8++;
				}
			}
		}
	}
	check_value=check();
	if(check_value==0)
		printf("We could not do it!!");
	else{
		for(i=0;i<=2*m;i++)
			for(j=0;j<=2*n;j++)
				result[i][j]=' ';
		for(i=1;i<=m;i++)
			for(j=1;j<=n;j++)
				result[2*i-1][2*j-1]=s[i][j];
		for(i=0;i<number;i++){
			x=position[0][i];
			y=position[1][i];
			switch(position[2][i]){
			case 1:
				for(j=0;j<lenth[i]-1;j++)	
					result[2*x-1][2*y+2*j]='-';
				break;
			case 2:
				for(j=0;j<lenth[i]-1;j++)	
					result[2*x+2*j][2*y+2*j]='\\';
				break;
			case 3:
				for(j=0;j<lenth[i]-1;j++)	
					result[2*x+2*j][2*y-1]='|';
				break;
			case 4:
				for(j=0;j<lenth[i]-1;j++)	
					result[2*x+2*j][2*y-2*j-2]='/';
				break;
			case 5:
				for(j=0;j<lenth[i]-1;j++)	
					result[2*x-1][2*y-2*j-2]='-';
				break;
			case 6:
				for(j=0;j<lenth[i]-1;j++)	
					result[2*x-2*j-2][2*y-2*j-2]='\\';
				break;
			case 7:
				for(j=0;j<lenth[i]-1;j++)	
					result[2*x-2*j-2][2*y-1]='|';
				break;
			case 8:
				for(j=0;j<lenth[i]-1;j++)	
					result[2*x-2*j-2][2*y+2*j]='/';
				break;
			}
		}
		for(i=0;i<=2*m;i++){
			for(j=0;j<=2*n;j++)
				printf("%c",result[i][j]);
			printf("\n");
		}
	}
	fclose(stdin);
	return 0;
}
