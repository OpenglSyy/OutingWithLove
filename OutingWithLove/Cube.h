#include "stdafx.h"

#ifndef _Cube_
#define _Cube_

class Cube{
public:
	vector<vector<vector<int>>> getFourRects(vector<int> coords,int sideLength){
		//12条线
		vector<vector<vector<int>>> lines;
		//四个面
		vector<vector<vector<int>>> rects;

		int a, b, c;
		int a1, b1, c1;
		a  = coords[0];
		a1 = coords[0] + sideLength;
		b  = coords[1];
		b1 = coords[1] + sideLength;
		c = coords[2];
		c1 = coords[2] + sideLength;
		
		vector<int> t_a; t_a.push_back(a); t_a.push_back(b); t_a.push_back(c);
		vector<int> t_b; t_a.push_back(a); t_a.push_back(b); t_a.push_back(c1);
		vector<int> t_c; t_a.push_back(a); t_a.push_back(b1); t_a.push_back(c);
		vector<int> t_d; t_a.push_back(a); t_a.push_back(b1); t_a.push_back(c1);


		vector<int> t_e; t_a.push_back(a1); t_a.push_back(b); t_a.push_back(c);
		vector<int> t_f; t_a.push_back(a1); t_a.push_back(b); t_a.push_back(c1);
		vector<int> t_g; t_a.push_back(a1); t_a.push_back(b1); t_a.push_back(c);
		vector<int> t_h; t_a.push_back(a1); t_a.push_back(b1); t_a.push_back(c1);
		
		vector<vector<int>> t; t.push_back(t_a); t.push_back(t_b); t.push_back(t_c); t.push_back(t_d);
		                       t.push_back(t_e); t.push_back(t_f); t.push_back(t_g); t.push_back(t_h);
							   
							   
							   for (int i = 0; i < t.size; i++)
							   {
								   for (int j = i + 1; j < t.size; j++)
								   {
									   if ((t[i].pop_back[0] == t[j].pop_back[0] && t[i].pop_back[1] == t[j].pop_back[1]) ||
										   (t[i].pop_back[0] == t[j].pop_back[0] && t[i].pop_back[2] == t[j].pop_back[2]) ||
										   (t[i].pop_back[1] == t[j].pop_back[1] && t[i].pop_back[2] == t[j].pop_back[2]))
									   {
										   vector<vector<int>> l;
										   l.push_back(t[i]);
										   l.push_back(t[j]);
										   lines.push_back(l);
									   }
								   }
							   }
							   
							   for (int i = 0; i < lines.size; i++)
							   {
								   for (int j = i+1; j < lines.size; j++)
								   {
									   vector<vector<int>> rect;
									   vector<vector<int>> l_i = lines[i];
									   vector<int> p_i_one = l_i[0];
									   vector<int> p_i_two = l_i[1];

									   vector<vector<int>> l_j = lines[j];
									   vector<int> p_j_one = l_j[0];
									   vector<int> p_j_two = l_j[1];

									   int rato_one = abs((p_i_one[0] - p_j_one[0]) + (p_i_one[1] - p_j_one[1]) + (p_i_one[2] - p_j_one[2]));
									   int rato_two = abs((p_i_one[0] - p_j_two[0]) + (p_i_one[1] - p_j_two[1]) + (p_i_one[2] - p_j_two[2]));
									   int rato_three = abs((p_i_two[0] - p_j_one[0]) + (p_i_two[1] - p_j_one[1]) + (p_i_two[2] - p_j_one[2]));
									   int rato_four = abs((p_i_two[0] - p_j_two[0]) + (p_i_two[1] - p_j_two[1]) + (p_i_two[2] - p_j_two[2]));
 
									   if ((rato_one == sideLength || rato_two == sideLength) && (rato_three == sideLength || rato_four == sideLength))
									   {
										   rect.push_back(p_i_one);
										   rect.push_back(p_i_two);
										   rect.push_back(p_j_one);
										   rect.push_back(p_j_two);
										   rects.push_back(rect);
									   }

								   }
							   }
							   return rects;
	}
};
#endif