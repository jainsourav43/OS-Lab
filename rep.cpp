#include <bits/stdc++.h>

using namespace std;

void print(vector<int> arr)
{
	cout<<endl;
	for(int i=0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void fifo(vector<int> input,int frame_count)
{
	vector<int> frames(frame_count,-1);
	int victim = 0;
	int falts = 0;
	for(int i=0;i<input.size();i++)
	{
		//first search
		bool found = false;
		for(int j = 0;j<frames.size(); j++)
		{
			if(frames[j] == input[i])
			{
				found = true;
				break;
			}
		}

		if(!found)
		{
			falts++;
			frames[victim] = input[i];
			victim = (victim+1)%frame_count;
		}

	}

	cout<<"\n"<<falts<<" misses occurred in FIFO\n";
}

void optimal(vector<int> input,int frame_count)
{
	vector<int> frames(frame_count,-1);
	int falts = 0;

	for(int i=0;i<input.size();i++)
	{
		//first search
		//cout<<"\ninput = "<<input[i]<<endl;
		bool found = false;
		for(int j = 0;j<frames.size(); j++)
		{
			if(frames[j] == input[i])
			{
				//cout<<"\n"<<input[i]<<" already in frames\n";
				found = true;
				break;
			}
		}

		if(!found)
		{
			// not found
			falts++;
			//first check if any space is empty
			bool space_available = false;
			for(int j = 0;j<frames.size();j++)
			{
				if(frames[j] == -1)
				{
					//space available
					space_available = true;
					frames[j] = input[i];
					break;
				}
			}
			if(!space_available)
			{
				vector<int> distances (frame_count,frame_count+1);
				
				for(int j=0;j<frame_count;j++)
				{
					distances[j] = 9999;
					for(int k=i+1;k<input.size();k++)
					{
						if(frames[j] == input[k])
						{
							distances[j] = k;
							break;
						}
					}
				}

				// find maximum of the distances
				int max_ = 0,index =-1;
				for(int j=0;j<frame_count;j++)
				{
					if(max_ < distances[j])
					{
						index = j;
						max_ = distances[j];
					}
				}

				// replace the index
				//cout<<"\npage "<<frames[index]<<" is selected as victim with distance "<<distances[index]<<endl;
				frames[index] = input[i];

			}
		}
		//print(frames);
	}

	cout<<"\n"<<falts<<" misses occurred in optimal\n";

}

void lru_counter(vector<int> input,int frame_count)
{
	vector<int> frames(frame_count,-1);
	vector<int> counters(frame_count,-1);
	int falts = 0;
	int counter = 1;

	for(int i=0;i<input.size();i++,counter++)
	{
		//first search

		//print(frames);
		bool found = false;
		for(int j = 0;j<frames.size(); j++)
		{
			if(frames[j] == input[i])
			{
				//cout<<"\n"<<input[i]<<" already in frames\n";
				found = true;
				//cout<<endl<<input[i]<<" found.";
				counters[j] = counter;
				break;
			}
		}

		if(found)
			continue;

		// not found

		falts++;

		bool space_available = false;
		// check if space avialable
		for(int j=0;j<frames.size();j++)
		{
			if(frames[j] == -1)
			{
				//space available
				space_available = true;
				frames[j] = input[i];
				counters[j] = counter;
				break;
			}
		}
		if(space_available)
				continue;

		// now replace page

		// select frame with lowest count
		int min_ = 9999;
		int index = -1;
		for(int j=0;j<frame_count;j++)
		{
			if(j == 0)
			{
				min_ = counters[0];
				index = 0;
			}
			else if(min_ > counters[j])
			{
				min_ = counters[j];
				index = j;
			}
		}

		// replace with index
		frames[index] = input[i];
		counters[index] = counter;
	}
	cout<<"\n\n";
	cout<<endl<<falts<<" in lru using counters\n";
}

int main()
{
	cout<<"\nEnter refrence string: ";
	int input,frames_count;
	vector<int> str;

	while(true)
	{
		cin>>input;
		if(input == -1)
				break;
		else
			str.push_back(input);
	}

	cout<<"\nEnter number of available frames : ";
	cin>>frames_count;


	// FIFO
	fifo(str,frames_count);
	optimal(str,frames_count);
	lru_counter(str,frames_count);

	return 0;
}