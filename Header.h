#pragma once

using namespace std;
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <vector>
#include <ios>

// A utility function to swap two elements
void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

//<----------------------------------------------------------------------------------------------------------------------------------------------------->

class job {
private:
	int numPages;
	int orgPos;
	int newPos;
	int posChange;
	bool check;
public:
	job() { numPages = 0; orgPos = 0; newPos = 0; posChange = 0; check = false; }
	~job() {}
	
	void setPages(int pages) {
		numPages = pages;
	}

	void setOrgPos(int org) {
		orgPos = org;
	}

	void setNewPos(int org) {
		newPos = org;
	}

	void setPosChange() {
		posChange = orgPos - newPos;
	}

	void checkOff() {
		check = true;
	}

	//<----------------------------------------------------------------------------------------------------------------------------------------------------->

	int getPages() {
		return numPages;
	}

	int getOrgPos() {
		return orgPos;
	}

	int getNewPos() {
		return newPos;
	}

	int getPosChange() {
		return posChange;
	}

	bool isChecked() {
		return check;
	}
};

struct minHeap{
	int* heaparray; // pointer to array of elements in heap
	int capacity;   // maximum possible size of min heap
	int heap_size;  // Current number of elements in min heap

	//<----------------------------------------------------------------------------------------------------------------------------------------------------->

	minHeap(int cap){
		heap_size = 0;
		capacity = cap;
		heaparray = new int[cap];
	}

	//<----------------------------------------------------------------------------------------------------------------------------------------------------->

	int left(int i) { return 2 * i + 1; }
	int right(int i) { return 2 * i + 2; }
	int parent(int i) { return (i - 1) / 2; }

	//<----------------------------------------------------------------------------------------------------------------------------------------------------->

	// Inserts a new key 'k' 
	void insertKey(int k){
		if (heap_size == capacity)
		{
			cout << "\nOverflow: Could not insertKey\n";
			return;
		}
		heap_size++;
		int i = heap_size - 1;
		heaparray[i] = k;

		// Fix the min heap property if it is violated
		while (i != 0 && heaparray[parent(i)] > heaparray[i])
		{
			swap(&heaparray[i], &heaparray[parent(i)]);
			i = parent(i);
		}
	}

	//<----------------------------------------------------------------------------------------------------------------------------------------------------->

	// Method to remove minimum element (or root) from min heap 
	int extractMin(){
		if (heap_size <= 0)
			return INT_MAX;
		if (heap_size == 1)
		{
			heap_size--;
			return heaparray[0];
		}

		// Store the minimum value, and remove it from heap 
		int root = heaparray[0];
		heaparray[0] = heaparray[heap_size - 1];
		heap_size--;
		MinHeapify(0);

		return root;
	}

	//<----------------------------------------------------------------------------------------------------------------------------------------------------->

	// A recursive method to heapify a subtree with the root at given index 
	// This method assumes that the subtrees are already heapified 
	void MinHeapify(int i){
		int l = left(i);
		int r = right(i);
		int smallest = i;

		if (l < heap_size && heaparray[l] < heaparray[i])
			smallest = l;

		if (r < heap_size && heaparray[r] < heaparray[smallest])
			smallest = r;

		if (smallest != i)
		{
			swap(&heaparray[i], &heaparray[smallest]);
			MinHeapify(smallest);
		}
	}

	//<----------------------------------------------------------------------------------------------------------------------------------------------------->

	void printArr(int jobsToRun) {
		for (int i = 0; i < jobsToRun; i++) {
			cout << heaparray[i] << " ";
		}
		cout << endl;
	}

};