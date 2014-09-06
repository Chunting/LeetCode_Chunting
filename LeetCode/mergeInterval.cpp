/******************************************************************
Merge Intervals 
Given a collection of intervals, merge all overlapping intervals.

For example,
 Given [1,3],[2,6],[8,10],[15,18],
 return [1,6],[8,10],[15,18]. 


******************************************************************/
#include< stdio.h >
#include< iostream >
#include< algorithm >
#include< vector >
using namespace std;
struct Interval {
	int start;
	int end;
	Interval(): start( 0 ), end( 0 ){};
	Interval( int x, int y ): start( x ), end( y ){};
};

bool compareInterval( const Interval& first, const Interval& second ) {
	return first.start < second.start;
}
vector< Interval > mergeInterval( vector<Interval>& intervals ) {
	int size = intervals.size();
	if( size < 2 )
		return intervals;
	sort( intervals.begin(), intervals.end(), compareInterval );
 int fStart = intervals[0].start;
        int fEnd = intervals[0].end;
        vector< Interval > newintervals;
        for( int i = 1; i< size; ++i ) {
           int curStart = intervals[i].start;
           int curEnd = intervals[i].end;
           if( fEnd >= curStart && fEnd <= curEnd ) {
                fEnd = curEnd;              
           } else if ( fEnd < curStart) {
               newintervals.push_back( Interval(fStart, fEnd ));
               fEnd = curEnd;
               fStart = curStart;
           }
        }
        newintervals.push_back( Interval(fStart, fEnd ));
        return newintervals;
}
/*****************************************************************
int main() {
	Interval t1( 1, 4 );
	Interval t2( 0, 4 );
	vector<Interval> intervals;
	intervals.push_back( t1 );
	intervals.push_back( t2 );
	vector < Interval > vec = mergeInterval( intervals );
	int size = vec.size();
	for( int j = 0; j < size; ++j ) {
		Interval temp = vec.at(j);
		cout<< temp.start <<"  "<<temp.end <<endl;
	}
	return 0;
}
*********************************************************************/