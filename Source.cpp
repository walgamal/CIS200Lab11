#include "Header.h"

int main() {
	int jobsToRun;
	int randNum;

	fstream outFile;
	outFile.open("results.txt");

	cout << "Please enter the number of print jobs to run: ";
	outFile << "Please enter the number of print jobs to run: ";
	cin >> jobsToRun;
	outFile << jobsToRun << endl;
	srand(time(NULL));
	
	vector<job> printJob(jobsToRun);
	vector<job> extractedJobs(jobsToRun);
	minHeap myMinHeap(jobsToRun);

	//<----------------------------------------------------------------------------------------------------------------------------------------------------->


	for (int i = 0; i < jobsToRun; i++) {
		randNum = rand() % 10 + 1;
		printJob[i].setPages(randNum);
		printJob[i].setOrgPos(i + 1);
		myMinHeap.insertKey(randNum);
	}

	//<----------------------------------------------------------------------------------------------------------------------------------------------------->

	for (int i = 0; i < jobsToRun; i++) {
		extractedJobs[i].setPages(myMinHeap.extractMin());
		extractedJobs[i].setNewPos(i+1);
		printJob[i].setNewPos(i + 1);
	}

	//<----------------------------------------------------------------------------------------------------------------------------------------------------->

	for (int i = 0; i < jobsToRun; i++) {
		for (int j = 0; j < jobsToRun; j++) {
			if (printJob[j].isChecked() == false && printJob[j].getPages() == extractedJobs[i].getPages()) {
				printJob[j].setNewPos(extractedJobs[i].getNewPos());
				extractedJobs[i].setOrgPos(printJob[j].getOrgPos());
				extractedJobs[i].checkOff();
				printJob[j].checkOff();
				break;
			}
		}
	}
	
	//<----------------------------------------------------------------------------------------------------------------------------------------------------->

	cout << endl;
	outFile << endl;

	cout << " {||} " << setw(29) << "Original Order" << setw(17) << " {||} " << endl;
	outFile << " {||} " << setw(29) << "Original Order" << setw(17) << " {||} " << endl;
	cout << setfill('=') <<  " {||} " << setw(15) << "" << setw(10) << " {||} " << setw(11) << "" << setw(10) << " {||} " << endl << setfill(' ');
	outFile << setfill('=') << " {||} " << setw(15) << "" << setw(10) << " {||} " << setw(11) << "" << setw(10) << " {||} " << endl << setfill(' ');
	cout << " {||} " << setw(15) << "Print Job #" << setw(10) << " {||} " << setw(11) << "Pages" << setw(10) << " {||} " << endl;
	outFile << " {||} " << setw(15) << "Print Job #" << setw(10) << " {||} " << setw(11) << "Pages" << setw(10) << " {||} " << endl;
	
	for (int i = 0; i < jobsToRun; i++) {
		cout << " {||} " << setw(15) << printJob[i].getOrgPos() << setw(10) << " {||} " << setw(11) << printJob[i].getPages() << setw(10) << " {||} " << endl;
		outFile << " {||} " << setw(15) << printJob[i].getOrgPos() << setw(10) << " {||} " << setw(11) << printJob[i].getPages() << setw(10) << " {||} " << endl;
	}

	cout << setfill('=') << " {||} " << setw(15) << "" << setw(10) << " {||} " << setw(11) << "" << setw(10) << " {||} " << endl << setfill(' ');
	outFile << setfill('=') << " {||} " << setw(15) << "" << setw(10) << " {||} " << setw(11) << "" << setw(10) << " {||} " << endl << setfill(' ');
	cout << endl << endl << endl;
	outFile << endl << endl << endl;
	
	//<----------------------------------------------------------------------------------------------------------------------------------------------------->

	cout << " {||} " << setw(52) << "Print Order" << setw(44) << " {||} " << endl;
	outFile << " {||} " << setw(52) << "Print Order" << setw(44) << " {||} " << endl;
	cout << setfill('=') << " {||} " << setw(15) << "" << setw(10) << " {||} " << setw(15) << "" << setw(10) << " {||} " << setw(11) << "" << setw(10) << " {||} " << setw(15) << "" << setw(10) << " {||} " << endl << setfill(' ');
	outFile << setfill('=') << " {||} " << setw(15) << "" << setw(10) << " {||} " << setw(15) << "" << setw(10) << " {||} " << setw(11) << "" << setw(10) << " {||} " << setw(15) << "" << setw(10) << " {||} " << endl << setfill(' ');
	cout << " {||} " << setw(15) << "Print Job #" << setw(10) << " {||} " << setw(15) << "Org. Job #" << setw(10) << " {||} " << setw(11) << "Pages"  << setw(10) << " {||} " << setw(15) << "Pos. Change" << setw(10) << " {||} " << endl;
	outFile << " {||} " << setw(15) << "Print Job #" << setw(10) << " {||} " << setw(15) << "Org. Job #" << setw(10) << " {||} " << setw(11) << "Pages" << setw(10) << " {||} " << setw(15) << "Pos. Change" << setw(10) << " {||} " << endl;

	for (int i = 0; i < jobsToRun; i++) {
		extractedJobs[i].setPosChange();

		cout << " {||} " << setw(15) << extractedJobs[i].getNewPos() << setw(10) << " {||} " << setw(15) << extractedJobs[i].getOrgPos() << setw(10) << " {||} " << setw(11) <<
			extractedJobs[i].getPages() << setw(10) << " {||} ";

		if (extractedJobs[i].getPosChange() > 0) {
			cout << setw(14) << "Up ";
		}
		else if (extractedJobs[i].getPosChange() < 0) {
			cout << setw(14) << "Down ";
		}
		else {
			cout << setw(15);
		}

		cout << abs(extractedJobs[i].getPosChange()) <<  setw(10) << " {||} " << endl;

		outFile << " {||} " << setw(15) << extractedJobs[i].getNewPos() << setw(10) << " {||} " << setw(15) << extractedJobs[i].getOrgPos() << setw(10) << " {||} " << setw(11) <<
			extractedJobs[i].getPages() << setw(10) << " {||} ";

		if (extractedJobs[i].getPosChange() > 0) {
			outFile << setw(14) << "Up ";
		}
		else if (extractedJobs[i].getPosChange() < 0) {
			outFile << setw(14) << "Down ";
		}
		else {
			outFile << setw(15);
		}

		outFile << abs(extractedJobs[i].getPosChange()) << setw(10) << " {||} " << endl;
	}

	cout << setfill('=') << " {||} " << setw(15) << "" << setw(10) << " {||} " << setw(15) << "" << setw(10) << " {||} " << setw(11) << "" << setw(10) << " {||} " << setw(15) << "" << setw(10) << " {||} " << endl << setfill(' ');
	outFile << setfill('=') << " {||} " << setw(15) << "" << setw(10) << " {||} " << setw(15) << "" << setw(10) << " {||} " << setw(11) << "" << setw(10) << " {||} " << setw(15) << "" << setw(10) << " {||} " << endl << setfill(' ');

	cout << endl << endl << endl;
	outFile << endl << endl << endl;
	//<----------------------------------------------------------------------------------------------------------------------------------------------------->

	float avgPosChange = 0;
	float sum = 0;
	int upSum = 0;
	int downSum = 0;

	vector<int> positionsMovedUp(upSum);
	vector<int> positionsMovedDown(downSum);

	for (int i = 0; i < jobsToRun; i++) {
		if (extractedJobs[i].getPosChange() > 0) {
			positionsMovedUp.push_back(extractedJobs[i].getPosChange());
			upSum++;
		}
		else if(extractedJobs[i].getPosChange() < 0){
			positionsMovedDown.push_back(extractedJobs[i].getPosChange());
			downSum++;
		}

		sort(positionsMovedUp.begin(), positionsMovedUp.end());
		sort(positionsMovedDown.begin(), positionsMovedDown.end());
		sum += abs(extractedJobs[i].getPosChange());
	}

	avgPosChange = sum / jobsToRun;

	//<----------------------------------------------------------------------------------------------------------------------------------------------------->

	cout << "CALCULATED RESULTS" << endl;
	outFile << "CALCULATED RESULTS" << endl;

	cout << "Total Positions Moved: " << sum << endl;
	outFile << "Total Positions Moved: " << sum << endl;

	cout << "Largest Move Forward: " << positionsMovedUp.back() << endl;
	cout << "Largest Move Backward: " << abs(positionsMovedDown.front()) << endl;
	cout << "Average Postion Change: " << avgPosChange << endl;

	outFile << "Largest Move Forward: " << positionsMovedUp.back() << endl;
	outFile << "Largest Move Backward: " << abs(positionsMovedDown.front()) << endl;
	outFile << "Average Postion Change: " << avgPosChange << endl;

	//<----------------------------------------------------------------------------------------------------------------------------------------------------->

	outFile.close();

	system("pause");
	return 0;
}