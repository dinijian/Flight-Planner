#include<bits/stdc++.h>
using namespace std;


#define V 27
//arr is true when we get the final shortest path
int count1=1;
int count2=0;

void clrscr()
{
   system("cls");
}
int minDistance(int dist[], bool arr[])
{

int min = INT_MAX, index;

for (int v = 0; v < V; v++)
{
	if (arr[v] == false && dist[v] < min)
    {


		min = dist[v], index = v;
    }
}
return index;
}

int minCost(int cost[], bool arr1[])
{

int min = INT_MAX, index;

for (int v = 0; v < V; v++)
{
	if (arr1[v] == false && cost[v] < min)
    {


		min = cost[v], index = v;
    }
}
return index;
}
void printpathdistance(int dist[],int parent[],int s, int j)
{
    // Base Case : If j is source
    if (parent[j] == - 1){
        cout<<j<<"->";
    return;
    }
    else
    {
        printpathdistance(dist,parent,s, parent[j]);
    cout<<j<<"->";
    }
}
void details(int dist[],int cost[],int s,int j)
{
 cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tDETAILED TRIP : \n "<<endl;
 cout<<"\t\t\t\t\t\tFrom "<<s<<" to "<<j<<" the shortest distance is "<<dist[j]<<"0 Kms"<<endl;

 cout<<"\t\t\t\t\t\tThe  fare for this trip : "<<"Rs. "<< cost[j]<<"00/-"<<endl;
 cout<<"\t\t\t\t\t\tThe time required to complete the trip : "<<(dist[j])/4<<" hr"<<endl;
}

void printpathcost(int cost[],int parent[],int s, int j)
{

    // Base Case : If j is source
    if (parent[j] == - 1){
        cout<<j<<"->";
    return;
    }
    else
    {
        printpathcost(cost,parent,s, parent[j]);
    cout<<j<<"->";
    }
}
void dijkstrashortestpath(int graph[V][V],int graphcost[V][V], int src, int dest, int ch )
{
    int cost[V];
	int dist[V];

	bool arr[V];

	int parent[V];

	for (int i = 0; i < V; i++)
    {
        cost[i]=INT_MAX;

		dist[i] = INT_MAX;
        arr[i] = false;
        parent[src]=-1;
    }
    cost[src]=0;
	dist[src] = 0;

	for (int count = 0; count < V-1; count++)
	{
	int u = minDistance(dist, arr);

	arr[u] = true;

	for (int v = 0; v < V; v++)
      {
		if (!arr[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v])
       {

            parent[v] = u;
			dist[v] = dist[u] + graph[u][v];
			cost[v]=cost[u]+graphcost[u][v];
	   }

      }
	}
	//else if(ch==2)
    {
        cout<<"\t\t\t\t\t\tShortest path : ";

        //printpathdistance(parent, dest);
         printpathdistance(dist,parent,src, dest);
         details(dist,cost,src,dest);

    }
}
void dijkstrashortestpathbycost(int graphcost[V][V],int graph[V][V], int src, int dest, int ch)
{

	int cost[V];
	int dist[V];

	bool arr1[V];

	int parent1[V];

	for (int i = 0; i < V; i++)
    {

        dist[i]=INT_MAX;
		cost[i] = INT_MAX;
        arr1[i] = false;
        parent1[src]=-1;

    }

	cost[src] = 0;  dist[src]=0;

	for (int count = 0; count < V-1; count++)
	{
	int u = minCost(cost, arr1);

	arr1[u] = true;

	for (int v = 0; v < V; v++)
      {
		if (!arr1[v] && graphcost[u][v] && cost[u] != INT_MAX && cost[u]+graphcost[u][v] < cost[v])
       {
            parent1[v] = u;
			cost[v] = cost[u] + graphcost[u][v];
            dist[v] = dist[u] + graph[u][v];
	   }

      }
	}
    {
        cout<<"\t\t\t\t\t\tShortest path By Cost : ";

        printpathcost(cost,parent1,src, dest);
        details(dist,cost,src,dest);
    }
}
int main()
{

int s,d,opt,opt1;    //----------------------------------------------------------------  //-----------------------------------------------------------------------------
string n;       //  0   1  2  3   4   5   6   7   8   9   10   11   12   13   14   15   16   17   18   19   20   21   22   23   24   25  26
int graph[V][V] = {{0,  5, 0, 0,  0,  0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {5,  0, 8, 0,  0,  0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
				   {0,  8, 0, 6,  0,  0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 6, 0,  10, 0,  0,  0,  0,  7,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 10, 0,  12, 0,  0,  0,  0,  0,   0,   16,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  12, 0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  11, 0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  11, 0,  9,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  9,  0,  16, 0,   0,   0,   0,   21,  0,   0,   0,   0,   0,   6,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 7,  0,  0,  0,  0,  16, 0,  3,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  3,  0,   2,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   12,  0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  2,   0,   9,   0,   0,   11,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  16, 0,  0,  0,  0,  0,  0,   9,   0,   14,  0,   22,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  0,   0,   14,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  21, 0,  0,   0,   0,   0,   0,   13,  7,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  0,   11,  22,  0,   13,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  0,   0,   0,   0,   7,   0,   0,   14,  0,   0,   0,   0,   0,   21,  0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   14,  0,   11,  0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   0,   11,  0,   9,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   9,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  6,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   15,  0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   15,  0,   13,  0,   20,  0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  12,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   13,  0,   19,  0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   21,  0,   0,   0,   0,   0,   19,  0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   20,  0,   0,   0,   2,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   2,   0,  8},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   8,  0},
					};


int graphcost[V][V] = {{0,  10, 0, 0,  0,  0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {10,  0, 16, 0,  0,  0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
				   {0,  16, 0, 12,  0,  0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 12, 0,  20, 0,  0,  0,  0,  14,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 20, 0,  24, 0,  0,  0,  0,  0,   0,   32,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  24, 0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  22, 0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  22, 0,  18,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  18,  0,  32, 0,   0,   0,   0,   42,  0,   0,   0,   0,   0,   12,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 14,  0,  0,  0,  0,  32, 0,  6,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  6,  0,   4,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   12,  0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  4,   0,   9,   0,   0,   22,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  32, 0,  0,  0,  0,  0,  0,   9,   0,   4,  0,   22,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  0,   0,   4,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  42, 0,  0,   0,   0,   0,   0,   26,  7,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  0,   22,  22,  0,   26,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  0,   0,   0,   0,   7,   0,   0,   28,  0,   0,   0,   0,   0,   21,  0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   28,  0,   22,  0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   0,   22,  0,   18,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   18,   0,   0,   0,   0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  12,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   30,  0,   0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   30,  0,   26,  0,   20,  0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  12,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   26,  0,   38,  0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   21,  0,   0,   0,   0,   0,   38,  0,   0,   0,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   20,  0,   0,   0,   8,  0},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   8,   0,  16},
                   {0,  0, 0, 0,  0,  0,  0,  0,  0,  0,  0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   16,  0},
					};

						time_t time_;
	time(&time_);

    startmenu:
       // while(1)
clrscr();
   cout<<"\t\t\t\t\t\t\t\t\t\t"<<ctime(&time_);
       cout<<"\n\t\t\t\t\t:::::::::::::::::::::::::::::::::::::";
       cout<<"\n\t\t\t\t\t::                                 ::";
       cout<<"\n\t\t\t\t\t::     ***********************     ::";
       cout<<"\n\t\t\t\t\t::     *                     *     ::";
       cout<<"\n\t\t\t\t\t::     *      WELCOME TO     *     ::";
       cout<<"\n\t\t\t\t\t::     *                     *     ::";
       cout<<"\n\t\t\t\t\t::     *    FLIGHT NAVIGATOR *     ::";
       cout<<"\n\t\t\t\t\t::     *                     *     ::";
       cout<<"\n\t\t\t\t\t::     ***********************     ::";
       cout<<"\n\t\t\t\t\t::                                 ::";
       cout<<"\n\t\t\t\t\t:::::::::::::::::::::::::::::::::::::\n\n";

cout<<"\t\t\t\t\t\t SELECT FROM FOLLOWING"<<endl;
//cout<<"\t\t\t\t\t\t1.BASIC DETAILS"<<endl;

cout<<"\t\t\t\t\t\t1.FULL PATH"<<endl;
cout<<"\t\t\t\t\t\t2.EXIT"<<endl;

cout<<"\t\t\t\t\t\tCHOICE - ";
cin>>opt;
switch(opt)
{


	case 1:
	    clrscr();
	    goto up2;

                up2:
        cout<<"\t\t\t\t\t\t\t\t\t\t"<<ctime(&time_);
       cout<<"\n\t\t\t\t\t:::::::::::::::::::::::::::::::::::::";
       cout<<"\n\t\t\t\t\t::                                 ::";
       cout<<"\n\t\t\t\t\t::     ***********************     ::";
       cout<<"\n\t\t\t\t\t::     *                     *     ::";
       cout<<"\n\t\t\t\t\t::     *        FULL         *     ::";
       cout<<"\n\t\t\t\t\t::     *                     *     ::";
       cout<<"\n\t\t\t\t\t::     *        PATH         *     ::";
       cout<<"\n\t\t\t\t\t::     *                     *     ::";
       cout<<"\n\t\t\t\t\t::     ***********************     ::";
       cout<<"\n\t\t\t\t\t::                                 ::";
       cout<<"\n\t\t\t\t\t:::::::::::::::::::::::::::::::::::::\n\n";

       cout<<endl<<endl;

       cout<<"\t\t\t\t\t\t1.BEST TRIP BY COST"<<endl;
cout<<"\t\t\t\t\t\t2.BEST TRIP BY DISTANCE"<<endl;
cout<<"\t\t\t\t\t\tCHOICE - ";
cin>>opt1;
switch(opt1)
{
    case 1:
        clrscr();
            goto up3;

                up3:
        cout<<"\t\t\t\t\t\t\t\t\t\t"<<ctime(&time_);
       cout<<"\n\t\t\t\t\t:::::::::::::::::::::::::::::::::::::";
       cout<<"\n\t\t\t\t\t::                                 ::";
       cout<<"\n\t\t\t\t\t::     ***********************     ::";
       cout<<"\n\t\t\t\t\t::     *                     *     ::";
       cout<<"\n\t\t\t\t\t::     *      BEST TRIP      *     ::";
       cout<<"\n\t\t\t\t\t::     *                     *     ::";
       cout<<"\n\t\t\t\t\t::     *      BY COST        *     ::";
       cout<<"\n\t\t\t\t\t::     *                     *     ::";
       cout<<"\n\t\t\t\t\t::     ***********************     ::";
       cout<<"\n\t\t\t\t\t::                                 ::";
       cout<<"\n\t\t\t\t\t:::::::::::::::::::::::::::::::::::::\n\n";

       cout<<endl<<endl;

        cout<<"\t\t\t\t\tEnter any station from 0-26"<<endl;
       cout<<"\t\t\t\t\t\tEnter your source : ";
cin>>s;
cout<<"\t\t\t\t\t\tEnter your destination : ";
cin>>d;
cout<<endl<<endl;

dijkstrashortestpathbycost(graphcost,graph, s, d, opt);

	cout<<endl<<endl;

	cout<<"\t\t\t\t\t\tDo you want to continue? : ";
	cin>>n;
	if(n=="YES"||n=="yes"||n=="Yes")
    {
        goto startmenu;
    }
    else
    {
        exit(0);
    }
	break;
	case 2:

        	    clrscr();
	    goto up4;

                up4:
        cout<<"\t\t\t\t\t\t\t\t\t\t"<<ctime(&time_);
       cout<<"\n\t\t\t\t\t:::::::::::::::::::::::::::::::::::::";
       cout<<"\n\t\t\t\t\t::                                 ::";
       cout<<"\n\t\t\t\t\t::     ***********************     ::";
       cout<<"\n\t\t\t\t\t::     *                     *     ::";
       cout<<"\n\t\t\t\t\t::     *     BEST TRIP       *     ::";
       cout<<"\n\t\t\t\t\t::     *                     *     ::";
       cout<<"\n\t\t\t\t\t::     *    BY DISTANCE      *     ::";
       cout<<"\n\t\t\t\t\t::     *                     *     ::";
       cout<<"\n\t\t\t\t\t::     ***********************     ::";
       cout<<"\n\t\t\t\t\t::                                 ::";
       cout<<"\n\t\t\t\t\t:::::::::::::::::::::::::::::::::::::\n\n";

       cout<<endl<<endl;
       cout<<"\t\t\t\t\t\tEnter any station from 0-26"<<endl;
       cout<<"\t\t\t\t\t\tEnter your source : ";
cin>>s;
cout<<"\t\t\t\t\t\tEnter your destination: ";
cin>>d;
cout<<endl<<endl;

	dijkstrashortestpath(graph,graphcost, s, d, opt);

	cout<<endl<<endl;

	cout<<"\t\t\t\t\t\tDo you want to continue? : ";
	cin>>n;
	if(n=="YES"||n=="yes"||n=="Yes")
    {
        goto startmenu;
    }
    else
    {
        exit(0);
    }
}
	return 0;
}}
