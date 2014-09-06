#include< stdio.h >
#include< iostream >
#include< vector >
using namespace std;
 int findmin ( vector<int> &prices, int start ) {
        int end = prices.size();
        if( end < start )
            return -1;
        int index = start;
        int min = 200;
        for ( index=start; index < end; ++index ) {
            if ( min >= prices[index]) {
                min = prices [index];
            } else {
                break;
            }
        }
		//if ( index >= end )
		//	index--;
        return --index;
    }
    int findmax ( vector<int> &prices, int start ) {
        int end = prices.size();
        if ( end < start )
            return -1;
        int index = start;
        int max = 0;
        for ( index = start; index < end; ++index ) {
            if ( max <= prices[index] )
                max = prices[index];
                else
                    break;
        }
	//	if ( index >= end )
	//		index--;
        return --index;
    }
    int maxProfit2(vector<int> &prices) {
        if ( prices.size() <= 1 )
            return 0;
        int _size = prices.size();
        int profit = 0;
        for ( int i=0; i < _size; ++i ){
            int buyindex = findmin( prices, i);
            int buy = prices[buyindex];
			if ( buyindex < _size - 1 ) {
            int sellindex = findmax( prices, buyindex + 1 );
            int sell = prices[sellindex];
            profit += sell - buy;
            i = sellindex ;
			}
        }
        return profit;
    }
	int maxProfit1( vector<int> & prices ) {
		int profit = 0;
		int _size = prices.size();
		for ( int i = 1; i< _size; ++i ) {
			int temp = prices[i] - prices[i-1];
			if( temp > 0 )
				profit += temp;
		}
		return profit;

	}
/**
	int main () {
		vector<int> prices;
		for ( int i = 0; i < 1000; ++i ) {
			prices.push_back( rand()%10000 );
		}
	//	prices.push_back( 2 );
	//	prices.push_back( 1 );
	//	prices.push_back( 2 );
	//	prices.push_back( 0 );
	//	prices.push_back( 1 );
		int maxp1 = maxProfit1( prices );
		int maxp2 = maxProfit2( prices );
		cout<< maxp1 <<"  "<< maxp2 <<endl;



	}
	**/