
#include <stdio.h>
#include <string.h>

struct candidateData{
	char candidateName[32];
	int candidateFormNo;
	long long int CandidateCnic;
	char candidateEmail[32];
	char candidatePass[32];
	float candidateResult;
};

struct employeData
{
    char employeName[32];
    int cardNo;
    long long int employeCnic;
    char designation[32];
    char city[32];
};

struct testCenters
{
	int testCenterNo;
	char testCenterCity[32];
	char testCenterSupervisor[32];
	long long int testCenterSupervisorCNIC;
	char allocationDate[32];
	char buildingType[32];

};

struct testInfo{

	char testName[32];
	char testType[32];
	int testCharges;
	char testDate[32];
	char lastDateToApply[32];
	int totalMarks;
	int passingMarks;
};

//Strcuture 1

void addcandidateData(struct candidateData d1[100],int* candidateSize) {

	if(*candidateSize<100) {
		
		printf("\nWelcome to data entry.here you can add your data\n");
		printf("\nEnter candidate name: ");
		scanf("%s",&d1[*candidateSize].candidateName);
		printf("Enter candidate NTS form no: ");
		scanf("%d",&d1[*candidateSize].candidateFormNo);
		printf("Enter CNIC of the candidate: ");
		scanf("%llu",&d1[*candidateSize].CandidateCnic);
		printf("Enter a valid email of the candidate: ");
		scanf("%s",&d1[*candidateSize].candidateEmail);
		printf("Set a password for candidate: ");
		scanf("%s",&d1[*candidateSize].candidatePass);
		printf("Enter previous NTS percentile of candidate: ");
		scanf("%f",&d1[*candidateSize].candidateResult);
		(*candidateSize)++;
		printf("\n\t\tDATA ADDED SUCESSFULLY\n");
	} else {
		printf("\nMaximum amount of candidate data has been entered.Input exceeds size");
	}
}

void totalCandidates(int* candidateSize) {
	printf("Number of total registered records be %d\n\n",*candidateSize);
}

void displayCandidateInfo(struct candidateData d1[100], int* candidateSize) {

	printf("\nWelcome to display section.Data of all the candidates will be displayed here\n");
	if(*candidateSize==0)
	{
		printf("\nNo records found!!\n\n");
	}
	else{
	for(int i=0; i<*candidateSize; i++) {
		printf("\n\nName of entry no %d is: %s",i+1,d1[i].candidateName);
		printf("\nNTS form no of entry no %d is: %d",i+1,d1[i].candidateFormNo);
		printf("\nCNIC of entry no %d is: %llu",i+1,d1[i].CandidateCnic);
		printf("\nE-mail adress of entry no %d is: %s",i+1,d1[i].candidateEmail);
		printf("\nPassword of entry no %d is %s",i+1,d1[i].candidatePass);
		printf("\nNTS percentile of entry no %d is: %.2f\n\n",i+1,d1[i].candidateResult);
		}
	}
}

void updateCandidate(struct candidateData d1[100],int* candidateSize) {
	int candidateRecordToUpdate;
	printf("Welcome to update menu.You can update your data here\n");
	printf("Enter the record you want to update: ");
	scanf("%d",&candidateRecordToUpdate);

	if(candidateRecordToUpdate<=*candidateSize) {
		for(int i=0; i<*candidateSize; i++) {
			int j=i+1;
			if(j==candidateRecordToUpdate) {
				printf("\n\nEnter updated name: ");
				scanf("%s",d1[i].candidateName);
				printf("\nEnter updated NTS form no: ");
				scanf("%d",&d1[i].candidateFormNo);
				printf("\nEnter updated CNIC: ");
				scanf("%llu",&d1[i].CandidateCnic);
				printf("\nEnter a valid updated email: ");
				scanf("%s",d1[i].candidateEmail);
				printf("\nSet an updated password: ");
				scanf("%s",d1[i].candidatePass);
				printf("\nEnter your updated NTS percentile: ");
				scanf("%f",&d1[i].candidateResult);
				printf("DATA UPDATED SUCCESSFULLY!!");
				break;
			} else {
				continue;
			}
		}
	} else {
		printf("Your input exceeds size!!");
	}
}

void deleteCandidateInfo(struct candidateData d1[],int* candidateSize) {

	int formNoOfCandidateToDelete,index;
	printf("Welcome to delete record.Here you can delete an option\n");
	printf("Enter the form no of the record you want to delete: ");
	scanf("%d",&formNoOfCandidateToDelete);
	if(formNoOfCandidateToDelete>*candidateSize) {
		printf("Your input exceeds candidateSize");
	} else {
		for(int i=0; i<*candidateSize; i++) {
			if(formNoOfCandidateToDelete= d1[i].candidateFormNo) {
				index=i;
			}
		}
		for(int j=index; j<=*candidateSize; j++) {
			strcpy(d1[j].candidateName,d1[j+1].candidateName);
			d1[j].candidateFormNo=d1[j+1].candidateFormNo;
			d1[j].CandidateCnic=d1[j+1].CandidateCnic;
			strcpy(d1[j].candidateEmail,d1[j+1].candidateEmail);
			strcpy(d1[j].candidatePass,d1[j+1].candidatePass);
			d1[j].candidateResult=d1[j+1].candidateResult;
			(*candidateSize)--;
			printf("The record has been deleted");
		}
	}
}

void topperCandidate(struct candidateData d1[100],int* candidateSize) {

	if(*candidateSize==0)
	{
		printf("No records found!!");
	}
	else{

	int highestResult=0,index1;
	for(int i=0; i<*candidateSize-1; i++) {
		if(d1[i].candidateResult>d1[i+1].candidateResult)
		{
		highestResult=d1[i].candidateResult;
		index1=i;
	}
	}
		if(d1[*candidateSize].candidateResult>highestResult)
	{
		index1=*candidateSize;
	}
	for(int j=0; j<=*candidateSize; j++) {
		if(j==index1) {
			printf("\nInformation of the topper this session is as follows: \n");
			printf("\nName: %s",d1[j].candidateName);
			printf("\nNTS form no: %d",d1[j].candidateFormNo);
			printf("\nCNIC: %llu",d1[j].CandidateCnic);
			printf("\nNTS percentile: %.2f",d1[j].candidateResult);
		} else{
			continue;
		}
	}
	}
}

void searchCandidate(struct candidateData d1[100] , int* candidateSize)
{
	int formNoOfTheCandidateToSearch,queryx2=0,indexforFormNoOfTheCandidateToSearch;
	printf("Enter the form no of candidate you want to search: ");
	scanf("%d",&formNoOfTheCandidateToSearch);

	for(int i=0;i<*candidateSize;i++)
	{
		if(formNoOfTheCandidateToSearch==d1[i].candidateFormNo)
		{
			indexforFormNoOfTheCandidateToSearch=i;
			queryx2++;

		}
	}
		
		if(queryx2==0)
		{
			printf("\nCANDIDATE RECORD NOT FOUND\n\n");
		}
		else{

				printf("Details of the candidate are as follows\n");
				printf("\n\nName: %s",d1[indexforFormNoOfTheCandidateToSearch].candidateName);
				printf("\nNTS form no: %d",d1[indexforFormNoOfTheCandidateToSearch].candidateFormNo);
				printf("\nCNIC: %llu",d1[indexforFormNoOfTheCandidateToSearch].CandidateCnic);
				printf("\nE-mail adress: %s",d1[indexforFormNoOfTheCandidateToSearch].candidateEmail);
				printf("\nPassword %s",d1[indexforFormNoOfTheCandidateToSearch].candidatePass);
				printf("\nNTS percentile: %.2f\n\n",d1[indexforFormNoOfTheCandidateToSearch].candidateResult);
		}

}

int shutdownCandidatePortal() 
{
	printf("\nThe system has shutdown\n\n");
	return 0;
}

//Structure 2
void addEmployeData(struct employeData d2[100],int* employeSize){

if(*employeSize<100) {
		printf("\n\nWelcome to Employee Data section.You can add the data of an employee here\n\n");
    printf("Enter the name of the employee: ");
    scanf("%s",&d2[*employeSize].employeName);
    printf("Enter the card no of the employee: ");
    scanf("%d",&d2[*employeSize].cardNo);
    printf("Enter the CNIC no of the employee(without dashes): ");
    scanf("%llu",&d2[*employeSize].employeCnic);
    printf("Enter the designation of the employee: ");
    scanf("%s",&d2[*employeSize].designation);
    printf("Enter the city the employee is serving in: ");
    scanf("%s",&d2[*employeSize].city);
    (*employeSize)++;
    printf("Data added sucessfully!!\n");

	} 
	
	else 
	{
		printf("\nMaximum amount of employe data has been entered.Input exceeds size");
	}
    
}

void totalEmployes(int* employeSize) {
	printf("Number of total registered records be %d\n\n",*employeSize);
}

void displayEmployeInfo(struct employeData d2[100],int* employeSize)
{
    printf("\nWelcome to data display.Data of all the employees will be displayed here\n");
	if(*employeSize==0)
	{
		printf("\nNo records found!!\n\n");
	}
	else{
	for(int i=0; i<*employeSize; i++) {
		printf("\n\nName of employee no %d is: %s",i+1,d2[i].employeName);
		printf("\nCard no of employee no %d is: %d",i+1,d2[i].cardNo);
		printf("\nCNIC of employee no %d is: %llu",i+1,d2[i].employeCnic);
		printf("\nDesignation of employee no %d is: %s",i+1,d2[i].designation);
		printf("\nAlloted City of employee no %d is %s",i+1,d2[i].city);
		}
	}
}

void updateEmploye(struct employeData d2[100],int* employeSize) {
	int employeRecordToUpdate;
	printf("Welcome to update menu.You can update your data here\n");
	printf("Enter the record you want to update: ");
	scanf("%d",&employeRecordToUpdate);

	if(employeRecordToUpdate<=*employeSize) {
		for(int i=0; i<*employeSize; i++) {
			int j=i+1;
			if(j==employeRecordToUpdate) {
				printf("\n\nEnter updated name: ");
				scanf("%s",d2[i].employeName);
				printf("\nEnter updated NTS employe card ni: ");
				scanf("%d",&d2[i].cardNo);
				printf("\nEnter updated CNIC of employe: ");
				scanf("%llu",&d2[i].employeCnic);
				printf("\nSet an updated designation");
				scanf("%s",d2[i].designation);
				printf("\nEnter your updated city: ");
				scanf("%s",&d2[i].city);
				printf("\nDATA UPDATED SUCESSFULLY!!\n\n");
				break;
			} else {
				continue;
			}
		}
	}
	
	 else {
		printf("Your input exceeds size");
	}
}

void deleteEmploye(struct employeData d2[],int* employeSize) {

	int employeCardNo,index2;
	printf("Welcome to delete record.Here you can delete an option\n");
	printf("Enter the form no of the record you want to delete: ");
	scanf("%d",&employeCardNo);
	if(employeCardNo>*employeSize) {
		printf("Your input exceeds size");
	} else {
		for(int i=0; i<*employeSize; i++) {
			if(employeCardNo= d2[i].cardNo) {
				index2=i;
			}
		}
		for(int j=index2; j<=*employeSize; j++) {
			strcpy(d2[j].employeName,d2[j+1].employeName);
			d2[j].cardNo=d2[j+1].cardNo;
			d2[j].employeCnic=d2[j+1].employeCnic;
			strcpy(d2[j].designation,d2[j+1].designation);
			strcpy(d2[j].city,d2[j+1].city);
			(*employeSize)--;
			printf("THE EMPLOYEE RECORD HAS BEEN DELETED\n");
		}
	}
}

void searchEmploye(struct employeData d2[], int* employeSize)
{
		int cardNoToSearch,q=0;
		printf("\nEnter the card no of the employe you want to search: ");
		scanf("%d",&cardNoToSearch);
		
		for(int i=0;i<*employeSize;i++)
		{
			if(d2[i].cardNo==cardNoToSearch)
			{
				cardNoToSearch=i;
				q++;
				break;
			}
			
			else{
				continue;
			}
		}

		if(q==0)
		{
			printf("\nEMPLOYEE NOT FOUND!!");
		}
		else{
		printf("\n\nName of employee is: %s",d2[cardNoToSearch].employeName);
		printf("\nCard no of employee is: %d",d2[cardNoToSearch].cardNo);
		printf("\nCNIC of employee no is: %llu",d2[cardNoToSearch].employeCnic);
		printf("\nDesignation of employee is: %s",d2[cardNoToSearch].designation);
		printf("\nAlloted City of employee is %s",d2[cardNoToSearch].city);
	}
}

int shutdownEmployeMenu()
{
	printf("\nThe system has shutdown\n\n");
	return 0;
}

void employesInCity(struct employeData d2[], int* employeSize)
{
	int cityName,noEmployes=0;
	printf("Enter the name of the city for the list of employes: ");
	scanf("%s",&cityName);

	for (int  i = 0; i < *employeSize; i++)
	{
		if(*d2[i].city==cityName)
		{
			printf("\n\nName of employee is: %s",d2[i].employeName);
		printf("\nCard no of employee is: %d",d2[i].cardNo);
		printf("\nCNIC of employee no is: %llu",d2[i].employeCnic);
		printf("\nDesignation of employee is: %s\n\n",d2[i].designation);
		noEmployes++;
		}
	}
	if(noEmployes==0)
			{
		printf("NO EMPLOYEES FOUND!!");
		}
}

//STRUCTURE 2
void addTestCenter(struct testCenters d3[], int* testCenterSize)
{
	if(*testCenterSize<100) {
		printf("\n\nWelcome to Test Centres Data section.You can register a test center here\n\n");
    printf("Enter the number of the test centre: ");
    scanf("%d",&d3[*testCenterSize].testCenterNo);
    printf("Enter the name of the city: ");
    scanf("%s",&d3[*testCenterSize].testCenterCity);
	printf("Enter the name of the supervisor: ");
    scanf("%s",&d3[*testCenterSize].testCenterSupervisor);
    printf("Enter the CNIC no of the supervisor(without dashes): ");
    scanf("%llu",&d3[*testCenterSize].testCenterSupervisorCNIC);
    printf("Enter the nature of the building used: ");
    scanf("%s",&d3[*testCenterSize].buildingType);
    printf("Enter the date of allocation of the test centre(DD-MM-YYYY): ");
    scanf("%s",&d3[*testCenterSize].allocationDate);
    (*testCenterSize)++;
    printf("Data added sucessfully!!\n");

	} else {
		printf("\nMaximum amount of centres have been registered.Input exceeds size");
	    }
    
}

void totalTestCenters(int* testCenterSize)
{
	printf("The total number of registered test centers is: %d",*testCenterSize);
}

void AllTestCenterInfo(struct testCenters d3[], int* testCenterSize)
{
	printf("\nWelcome to data display.Data of all the test centers will be displayed here\n");
	if(*testCenterSize==0)
	{
		printf("\nNo records found!!\n\n");
	}
	else{
	for(int i=0; i<*testCenterSize; i++) {
		printf("\n\nAlloted no of test center %d is: %d",i+1,d3[i].testCenterNo);
		printf("\nCity where center no %d is located is: %s",i+1,d3[i].testCenterCity);
		printf("\nSupervisor of center no %d is: %s",i+1,d3[i].testCenterSupervisor);
		printf("\nCNIC of supervisor of center no %d is: %llu",i+1,d3[i].testCenterSupervisorCNIC);
		printf("\nNature of building of center no %d is %s",i+1,d3[i].buildingType);
		printf("\nDate of allocation of center no %d is %s",i+1,d3[i].allocationDate);
		}
	}
}

void updateTestCenter(struct testCenters d3[], int* testCenterSize)
{
	int testCenterToUpdate;
	printf("Welcome to update menu.You can update your data here\n");
	printf("Enter the test center you want to update: ");
	scanf("%d",&testCenterToUpdate);

	if(testCenterToUpdate<=*testCenterSize) {
		for(int i=0; i<*testCenterSize; i++) {
			int j=i+1;
			if(j==testCenterToUpdate) {
		printf("Enter the updated number of the test centre: ");
    	scanf("%d",&d3[j].testCenterNo);
    	printf("Enter the name of the updated city: ");
    	scanf("%s",&d3[j].testCenterCity);
		printf("Enter the name of the updated supervisor: ");
    	scanf("%s",&d3[j].testCenterSupervisor);
    	printf("Enter the CNIC no of the updated supervisor(without dashes): ");
   		 scanf("%llu",&d3[j].testCenterSupervisorCNIC);
    	printf("Enter the nature of the updated building used: ");
    	scanf("%s",&d3[j].buildingType);
    	printf("Enter the updated date of allocation of the test centre(DD-MM-YYYY): ");
    	scanf("%s",&d3[j].allocationDate);
		break;
			} else {
				continue;
			}
		}
	} else {
		printf("Your input exceeds size");
	}
}

void deleteTestCenter(struct testCenters d3[100],int* testCenterSize)
{
		int testCenterToDelete,index3;

	printf("Welcome to delete record.Here you can delete an option\n");
	printf("Enter the center no of the record you want to delete: ");
	scanf("%d",&testCenterToDelete);
	if(*testCenterSize==0) {
		printf("NO TEST RECORDS FOUND!!");
	} else {
		for(int i=0; i<*testCenterSize; i++) {
			if(testCenterToDelete== d3[i].testCenterNo) {
				index3=i;
			}
		}
		for(int j=index3; j<=*testCenterSize; j++) {
			strcpy(d3[j].testCenterCity,d3[j+1].testCenterCity);
			d3[j].testCenterNo=d3[j+1].testCenterNo;
			d3[j].testCenterSupervisorCNIC=d3[j+1].testCenterSupervisorCNIC;
			strcpy(d3[j].testCenterSupervisor,d3[j+1].testCenterSupervisor);
			strcpy(d3[j].buildingType,d3[j+1].buildingType);
			strcpy(d3[j].allocationDate,d3[j+1].allocationDate);
			(*testCenterSize)--;
			printf("THE TEST CENTER RECORD HAS BEEN DELETED\n");
		}
	}

	}

void searchSupervisor(struct testCenters d3[100],int* testCenterSize)
{
	int supervisorSearchIndex,queryx=0;
	printf("\nEnter the alloted number of the test center of which you want to search the supervisor: ");
	scanf("%d",&supervisorSearchIndex);
	for(int i=0;i<*testCenterSize;i++)
	{
		if(d3[i].testCenterNo==supervisorSearchIndex)
		{
		supervisorSearchIndex=i;
		queryx++;
	}
	else{
		continue;
	}
}
if(queryx==0){
	printf("\nTEST CENTER NOT FOUND!!\n\n");
}
else{
	printf("\nThe supervisor at the searched center is %s\n\n",d3[supervisorSearchIndex].testCenterSupervisor);
	}
}

void testCentersInCity(struct testCenters d3[100],int* testCenterSize)
{
	int noOfTestCentersInCity=0;
	char nameOfTheCity[32];
	printf("\nEnter the city you want to search for: ");
	scanf("%s",&nameOfTheCity);

	for(int i=0;i<*testCenterSize;i++)
	{
		int testCentersInCityReturnValue = strcasecmp(nameOfTheCity,d3[i].testCenterCity);
		if(testCentersInCityReturnValue==0)
		{
			noOfTestCentersInCity++;
		}
		else{
			continue;
		}
	}
	printf("No of test centers in the entered city are %d",noOfTestCentersInCity);
}

int shutdownTestCenterMenu()
{
	printf("\nThe system has shutdown\n\n");
	return 0;
}

//Structure 4
void addTest(struct testInfo d4[100], int* noOfTests)
{
	if(*noOfTests<100) {
		printf("\nWelcome to data entry.here you can add your data\n");
		printf("\nEnter test name: ");
		scanf("%s",&d4[*noOfTests].testName);
		printf("Enter NTS test type (APTITUDE(A), GENERAL(G), LANGUAGE(L)): ");
		scanf("%s",&d4[*noOfTests].testType);
		printf("Enter total charges for the test in PKR: ");
		scanf("%d",&d4[*noOfTests].testCharges);
		printf("Enter total marks of the test: ");
		scanf("%d", &d4[*noOfTests].totalMarks);
		printf("Enter passing marks for the test: ");
		scanf("%d",&d4[*noOfTests].passingMarks);
		printf("Enter the date of the test(DD-MM-YYYY): ");
		scanf("%s",&d4[*noOfTests].testDate);
		printf("Enter the last date to apply for the test(DD-MM-YYYY): ");
		scanf("%s",&d4[*noOfTests].lastDateToApply);
		(*noOfTests)++;
		printf("\n\t\tDATA ADDED SUCESSFULLY\n");
	} else {
		printf("\nMaximum amount of tests have been registered.Input exceeds size\a\n");
	}
}

void totalNoOfTests(int* noOfTests)
{
	printf("The total number of registered tests are %d",*noOfTests);
}

void allTestsInfo(struct testInfo d4[100], int* noOfTests)
{
	printf("\nWelcome to data display.Data of all the registered tests will be displayed here\n");
	if(*noOfTests==0)
	{
		printf("\nNo records found!!\n\n");
	}
	else{
	for(int i=0; i<*noOfTests; i++) {
		printf("\nTest name: %s",d4[i].testName);
		printf("\nNTS test type (APTITUDE(A), GENERAL(G), LANGUAGE(L)): %s",d4[i].testType);
		printf("\nTotal charges for the test in PKR: %d ", d4[i].testCharges);
		printf("\nTotal marks of the test: %d",d4[i].totalMarks);
		printf("\nPassing marks for the test: %d",d4[i].passingMarks);
		printf("\nDate of the test: %s",d4[i].testDate);
		printf("\nLast date to apply for the test: %s",d4[i].lastDateToApply);
		}
	}
}


void updateTestInfo(struct testInfo d4[], int* noOfTests)
{
	int testInfoToUpdate;
	printf("Welcome to update menu.You can update your data here\n");
	printf("Enter the registred test you want to update: ");
	scanf("%d",&testInfoToUpdate);

	if(testInfoToUpdate<=*noOfTests) {
		for(int i=0; i<*noOfTests; i++) {
			int j=i+1;
			if(j==testInfoToUpdate) {
		printf("\nWelcome to data entry.here you can add your data\n");
		printf("\nEnter updated test name: ");
		scanf("%s",&d4[j].testName);
		printf("Enter updated NTS test type (APTITUDE(A), GENERAL(G), LANGUAGE(L)): ");
		scanf("%s",&d4[j].testType);
		printf("Enter updated charges for the test in PKR: ");
		scanf("%d",&d4[j].testCharges);
		printf("Enter updated total marks of the test: ");
		scanf("%d", &d4[j].totalMarks);
		printf("Enter updated passing marks for the test: ");
		scanf("%d",&d4[j].passingMarks);
		printf("Enter the updated date of the test(DD-MM-YYYY): ");
		scanf("%s",&d4[j].testDate);
		printf("Enter the updated last date to apply for the test(DD-MM-YYYY): ");
		scanf("%s",&d4[j].lastDateToApply);
		printf("\nDATA UPDATED SUCCESSFULLY!!");
		break;
			} else {
				continue;
			}
		}
	} 
	
	else {
		printf("Your input exceeds size\a\n");
	}
}

void deleteTestInfo(struct testInfo d4[100],int* noOfTests)
{
		char testInfoToDelete[32];
		int index12;
	printf("Welcome to delete record.Here you can delete an option\n");
	printf("Enter the test date of the record you want to delete(DD-MM-YYYY): ");
	scanf("%s",&testInfoToDelete);

		if(*noOfTests==0)
		{
			printf("NO TEST RECORDS FOUND!!");
		}

		else{
		for(int i=0; i<*noOfTests; i++) {
			if( strcmp(testInfoToDelete,d4[i].testDate)==0) {
				index12=i;
			}
		}

		for(int j=index12; j<*noOfTests; j++) {
			strcpy(d4[j].testName,d4[j+1].testName);
			d4[j].testCharges=d4[j+1].testCharges;
			d4[j].totalMarks=d4[j+1].totalMarks;
			d4[j].passingMarks=d4[j+1].passingMarks;
			strcpy(d4[j].testType,d4[j+1].testType);
			strcpy(d4[j].testDate,d4[j+1].testDate);
			strcpy(d4[j].lastDateToApply,d4[j+1].lastDateToApply);
			(*noOfTests)--;
			printf("THE TEST REGISTRATION RECORD HAS BEEN DELETED\n");
		}
		
	}

}

void feeChecker(struct testInfo d4[], int* noOfTests)
{
	char testNameToCheckCharges[32];
	int testToCheckChargesIndex,testToCheckChargesQuery=0;
	printf("Enter the name of the test to check amount of charges: ");
	scanf("%s",&testNameToCheckCharges);

	for(int i=0;i<*noOfTests;i++)
	{
		if (stricmp(testNameToCheckCharges,d4[i].testName)==0)
		{
			testToCheckChargesIndex=i;
			testToCheckChargesQuery++;
		}
	}

	if(testToCheckChargesQuery==0)
	{
		printf("\nRECORD NOT FOUND\a\n");
	}
	else
	{

		printf("Charges in PKR for the requested test be %d",d4[testToCheckChargesIndex].testCharges);
	}
}

void testDateChecker(struct testInfo d4[],int* noOfTests)
{
	char testNameToCheckDate[32];
	int testToCheckDateIndex,testToCheckDateQuery=0;
	printf("Enter the name of the test to check test date: ");
	scanf("%s",&testNameToCheckDate);

	for(int i=0;i<*noOfTests;i++)
	{
		if (stricmp(testNameToCheckDate,d4[i].testName)==0)
		{
			testToCheckDateIndex=i;
			testToCheckDateQuery++;
		}
	}

	if(testToCheckDateQuery==0)
	{
		printf("\nRECORD NOT FOUND\a\n");
	}
	else
	{

		printf("Date of test for the requested record be %s",d4[testToCheckDateIndex].testDate);
	}
}

void testLastDateChecker(struct testInfo d4[], int* noOfTests)
{
	char testNameToCheckLastDate[32];
	int testToCheckLastDateIndex,testToCheckLastDateQuery=0;
	printf("Enter the name of the test to check last date to apply: ");
	scanf("%s",&testNameToCheckLastDate);

	for(int i=0;i<*noOfTests;i++)
	{
		if (stricmp(testNameToCheckLastDate,d4[i].testName)==0)
		{
			testToCheckLastDateIndex=i;
			testToCheckLastDateQuery++;
		}
	}

	if(testToCheckLastDateQuery==0)
	{
		printf("\nRECORD NOT FOUND\a\n");
	}
	else
	{

		printf("Last Date for application of test for the requested record be %s",d4[testToCheckLastDateIndex].lastDateToApply);
	}
}

int shutdownTestInfoMenu()
{

	printf("\nThe system has shutdown\n\n");
	return 0;

}


//The following report operation assign a duty to an employee
void report1(struct employeData d2[],struct testCenters d3[], int *testCenterSize, int *totalEmployes)
{
	int cardNoToAssignDuty;
	printf("Enter the card no of the employee to assign a duty: ");
	scanf("%d",&cardNoToAssignDuty);
	printf("\n\n");

	if(*totalEmployes==0)
	{
		printf("No employees found!!\a\a");
	}

	else
	{

	for(int i=0;i<*totalEmployes;i++)
	{
	if(cardNoToAssignDuty==d2[i].cardNo)
	{
			for(int j=0;j<*testCenterSize;j++)
			{
			if(stricmp(d2[j].city, d3[j].testCenterCity)==0)
			{
					printf("Test Center no %d in the city %s assigned for duty to\nName: %s\nCard no: %d\n\n",d3[i].testCenterNo,d3[i].testCenterCity,d2[i].employeName,d2[i].cardNo);
					printf("\n\n\tASSIGNMENT SUCCESSFUL\n\n");
					break;			
			}
		}
		
	}
	else{

		printf("No employee with the given card no found!!\a");
	}
		}
			}
}


//Main Function
int main()
{
	int employeSize=0;
	int testCenterSize=0;
	int candidateSize=0;
	int noOfTests=0;

	struct candidateData d1[100];
    struct employeData d2[100];
	struct testCenters d3[100];
	struct testInfo d4[100];
	int choice2=1,choice3=1,choice1=1,choice4=1,choice5=1;
	char choiceAtMainMenu;

//candidate files
	FILE *f1;
			f1=fopen("candidates.txt", "r");

			fscanf(f1,"%d\n\n",&candidateSize);

			for(int i=0;i<candidateSize;i++)
			{

			fscanf(f1,"%s || %d || %llu || %s || %s || %f ||\n",&d1[i].candidateName,&d1[i].candidateFormNo,&d1[i].CandidateCnic,&d1[i].candidateEmail,&d1[i].candidatePass,&d1[i].candidateResult);

			}

			fclose(f1);

//employee files
	FILE *f3;
			f3=fopen("employees.txt", "r");

			fscanf(f3,"%d\n\n",&employeSize);

			for(int i=0;i<employeSize;i++)
			{

			fscanf(f3,"%s || %d || %llu || %s || %s ||\n",&d2[i].employeName,&d2[i].cardNo,&d2[i].employeCnic,&d2[i].designation,&d2[i].city);

			}

			fclose(f3);

//test centre files
	FILE *f5;
			f5=fopen("testCenters.txt", "r");

			fscanf(f5,"%d\n\n",&testCenterSize);

			for(int i=0;i<testCenterSize;i++)
			{

			fscanf(f5,"%d || %s || %s || %llu || %s || %s ||\n",&d3[i].testCenterNo,&d3[i].testCenterCity,&d3[i].testCenterSupervisor,&d3[i].testCenterSupervisorCNIC,&d3[i].buildingType,&d3[i].allocationDate);

			}

			fclose(f5);

//test info files
	FILE *f7;
			f7=fopen("testInfo.txt", "r");

			fscanf(f7,"%d\n\n",&noOfTests);

			for(int i=0;i<noOfTests;i++)
			{

			fscanf(f7,"%s || %s || %d || %d || %d || %s || %s\n",&d4[i].testName,&d4[i].testType,&d4[i].testCharges,&d4[i].totalMarks,&d4[i].passingMarks,&d4[i].testDate,&d4[i].lastDateToApply);

			}

			fclose(f7);


//START OF THE CREAM
		while(1)
		{

		printf("\n\n\t\t\tWELCOME TO THE NATIONAL TESTING SERVICE PORTAL\n\t\t\t\t\tHow can we help you!\n\n1.Candidate Menu\n2.Employee menu\n3.Test Center Menu\n4.Test Registration\n5.Assign Duty\nENTER 'E' TO EXIT\n\n");
		scanf("%c",&choiceAtMainMenu);

			
			if(choiceAtMainMenu=='E' || choiceAtMainMenu== 'e')
			{
			printf("\nYOU HAVE EXIT THE PORTAL\n\n");
			return 0;
			}

			else if(choiceAtMainMenu=='1'){

			while(choice1!=0)
			{
			printf("\n\n\t\t\tWelcome to the NTS CANDIDATE portal\n\nEnter a choice\n1.Add Candiadate Data\n2. Display total number of register records\n3. Display all information\n4. Update specific record\n5. Delete specific record\n6. Display topper student report\n7.Search a student\n8. Shutdown system\nEnter 0 to exit\n\n");
		scanf("%d",&choice1);

		switch(choice1) 
		{
			
			case 0:
			break;
			
			case 1:
			{
				addcandidateData(d1, &candidateSize);

				//candidate files
			FILE *f2;
			f2=fopen("candidates.txt", "w");

			fprintf(f2,"%d\n\n", candidateSize);
			
			for(int i=0;i<candidateSize;i++)
			{
				fprintf(f2,"%s || %d || %llu || %s || %s || %f ||\n", d1[i].candidateName, d1[i].candidateFormNo, d1[i].CandidateCnic, d1[i].candidateEmail, d1[i].candidatePass, d1[i].candidateResult);
			
			}

			fclose(f2);
			
			}
			break;
			
			
			case 2:
			{
			totalCandidates(&candidateSize);

			FILE *f2;
			f2=fopen("candidates.txt", "w");

			fprintf(f2,"%d\n\n", candidateSize);

			fclose(f2);
			
			}
			break;

			case 3:
			displayCandidateInfo(d1, &candidateSize);
			break;

			case 4:
			{

			updateCandidate(d1, &candidateSize);

			//candidate files

			FILE *f2;

			f2=fopen("candidates.txt", "w");

			for(int i=0;i<candidateSize;i++)

			{

			fprintf(f2,"%s || %d || %llu || %s || %s || %f ||\n", d1[i].candidateName,d1[i].candidateFormNo,d1[i].CandidateCnic,d1[i].candidateEmail,d1[i].candidatePass,d1[i].candidateResult);

			}

			fclose(f2);

			}
			break;

			case 5:
			{
			deleteCandidateInfo(d1, &candidateSize);

			//candidate files
			FILE *f2;
			f2=fopen("candidates.txt", "w");

			fprintf(f2,"%d\n\n", candidateSize);
			
			for(int i=0;i<candidateSize;i++)
			{
				fprintf(f2,"%s || %d || %llu || %s || %s || %f ||\n", d1[i].candidateName,d1[i].candidateFormNo,d1[i].CandidateCnic,d1[i].candidateEmail,d1[i].candidatePass,d1[i].candidateResult);
			
			}

			fclose(f2);
			}
			break;

			case 6:
			topperCandidate(d1, &candidateSize);
			break;

			case 7:
			searchCandidate(d1, &candidateSize);
			break;

			case 8:
			shutdownCandidatePortal();
			break;
			
			
			
			default:
			printf("You entered invalid choice!!\a");
		}
			}
			}

			
		
		


		else if(choiceAtMainMenu=='2'){
				
				while(choice2!=0) {

		printf("\n\n\t\t\tWelcome to the NTS EMPLOYEE portal\n\nEnter a choice\n1.Add data\n2. Display total number of register records\n3. Display all information\n4. Update specific record\n5. Delete specific record\n6. Search an employee\n7. Shutdown system\n8.Search all employees in a city\nEnter 0 to exit\n\n");
		scanf("%d",&choice2);
		
		switch(choice2) {
			
			case 0:
			break;
			
			case 1:
			{
			addEmployeData(d2, &employeSize);

			//employee files
			FILE *f4;
			f4=fopen("employees.txt", "w");

			fprintf(f4,"%d\n\n", employeSize);
			
			for(int i=0;i<employeSize;i++)
			{
				fprintf(f4,"%s || %d || %llu || %s || %s ||\n",d2[i].employeName,d2[i].cardNo,d2[i].employeCnic,d2[i].designation,d2[i].city);
			
			}

			fclose(f4);
			}
			break;

            case 2:
			totalEmployes(&employeSize);
			break;

            case 3:
			displayEmployeInfo(d2, &employeSize);
			break;

			case 4:
			{
			updateEmploye( d2, &employeSize);

			//employee files
			FILE *f4;
			f4=fopen("employees.txt", "w");

			fprintf(f4,"%d\n\n", employeSize);
			
			for(int i=0;i<employeSize;i++)
			{
				fprintf(f4,"%s || %d || %llu || %s || %s ||\n",d2[i].employeName,d2[i].cardNo,d2[i].employeCnic,d2[i].designation,d2[i].city);
			
			}

			fclose(f4);
		}
			break;

			case 5:
			{
			deleteEmploye(d2, &employeSize);

			//employee files
			FILE *f4;
			f4=fopen("employees.txt", "w");

			fprintf(f4,"%d\n\n", employeSize);
			
			for(int i=0;i<employeSize;i++)
			{
				fprintf(f4,"%s || %d || %llu || %s || %s ||\n",d2[i].employeName,d2[i].cardNo,d2[i].employeCnic,d2[i].designation,d2[i].city);
			
			}

			fclose(f4);
			}
			break;

			case 6:
			searchEmploye(d2, &employeSize);
			break;

			case 7:
			shutdownEmployeMenu();
			break;

			case 8:
			employesInCity(d2, &employeSize);
			break;
            
			default:
			printf("You entered invalid choice!!\a");
		}
	} 
	break;
}
		else if(choiceAtMainMenu=='3'){

			while(choice3!=0) {
		printf("\n\n\t\t\tWelcome to the NTS Test Center portal\n\nEnter a choice\n1.Add test Center\n2. Display total number of registered test centers\n3. Display all test centers information\n4. Update specific test center record\n5. Delete specific test center record\n6. Supervisor at the centre\n7.Total test centers in city\n8. Shutdown system\nEnter 0 to exit\n\n");
		scanf("%d",&choice3);
		switch(choice3) {
			
			case 0:
			break;
			
			case 1:
			{
			addTestCenter(d3, &testCenterSize);

			//testCenter files

			FILE *f6;
			f6=fopen("testCenters.txt", "w");

			fprintf(f6,"%d\n\n", testCenterSize);
			
			for(int i=0;i<testCenterSize;i++)
			{
				fprintf(f6,"%d || %s || %s || %llu || %s || %s ||\n",d3[i].testCenterNo,d3[i].testCenterCity,d3[i].testCenterSupervisor,d3[i].testCenterSupervisorCNIC,d3[i].buildingType,d3[i].allocationDate);
			
			}

			fclose(f6);
			}
			break;

            case 2:
			{
			totalTestCenters(&testCenterSize);

			//testCenter files

			FILE *f6;
			f6=fopen("testCenters.txt", "w");

			fprintf(f6,"%d\n\n",testCenterSize);

			fclose(f6);
			}
			break;

            case 3:
			AllTestCenterInfo(d3, &testCenterSize);
			break;

			case 4:
			{
			updateTestCenter( d3, &testCenterSize);

			//testCenter files

			FILE *f6;
			f6=fopen("testCenters.txt", "w");

			fprintf(f6,"%d\n\n", &testCenterSize);
			
			for(int i=0;i<testCenterSize;i++)
			{
				fprintf(f6,"%d || %s || %s || %llu || %s || %s ||\n",d3[i].testCenterNo,d3[i].testCenterCity,d3[i].testCenterSupervisor,d3[i].testCenterSupervisorCNIC,d3[i].buildingType,d3[i].allocationDate);
			
			}

			fclose(f6);
			}
			break;

			case 5:
			{
			deleteTestCenter(d3, &testCenterSize);

			//testCenter files

			FILE *f6;
			f6=fopen("testCenters.txt", "w");

			fprintf(f6,"%d\n\n", testCenterSize);
			
			for(int i=0;i<testCenterSize;i++)
			{
				fprintf(f6,"%d || %s || %s || %llu || %s || %s ||\n",d3[i].testCenterNo,d3[i].testCenterCity,d3[i].testCenterSupervisor,d3[i].testCenterSupervisorCNIC,d3[i].buildingType,d3[i].allocationDate);
			
			}

			fclose(f6);
			}
			break;

			case 6:
			searchSupervisor(d3, &testCenterSize);
			break;

			case 7:
			testCentersInCity(d3, &testCenterSize);
			break;

			case 8:
			shutdownTestCenterMenu();
			break;
            
			default:
			printf("You entered invalid choice!!\a");
		}
	} 
	break;
}

			else if(choiceAtMainMenu=='4'){
				while(choice4!=0) {
		printf("\n\n\t\t\tWelcome to the NTS Test Registration portal\n\nEnter a choice\n1.Add test information\n2. Display total number of registered tests at time\n3. Display all test information\n4. Update specific test registeration record\n5. Delete specific test registration record\n6.Fee checker for the test \n7.Check test date\n8.Check Last date to apply\n9. Shutdown system\nEnter 0 to exit\n\n");
		scanf("%d",&choice4);
		switch(choice4) {
			
			case 0:
			break;
			
			case 1:
			{
			addTest(d4, &noOfTests);

			//testInfo files
			FILE *f8;
			f8=fopen("testInfo.txt", "w");

			fprintf(f8,"%d\n\n", noOfTests);
			
			for(int i=0;i<noOfTests;i++)
			{
				fprintf(f8,"%s || %s || %d || %d || %d || %s || %s ||\n",d4[i].testName,d4[i].testType,d4[i].testCharges,d4[i].totalMarks,d4[i].passingMarks,d4[i].testDate,d4[i].lastDateToApply);
			
			}

			fclose(f8);
			}
			break;

            case 2:
			{
			totalNoOfTests(&noOfTests);

			//testInfo files
			FILE *f8;
			f8=fopen("testInfo.txt", "w");

			fprintf(f8,"%d\n\n", noOfTests);

			fclose(f8);
			}
			break;

            case 3:
			allTestsInfo(d4, &noOfTests);
			break;

			case 4:
			{
			updateTestInfo( d4, &noOfTests);
			//testInfo files
			FILE *f8;
			f8=fopen("testInfo.txt", "w");

			fprintf(f8,"%d\n\n", noOfTests);
			
			for(int i=0;i<noOfTests;i++)
			{
				fprintf(f8,"%s || %s || %d || %d || %d || %s || %s ||\n",d4[i].testName,d4[i].testType,d4[i].testCharges,d4[i].totalMarks,d4[i].passingMarks,d4[i].testDate,d4[i].lastDateToApply);
			
			}

			fclose(f8);

			}
			break;

			case 5:
			{
				
			deleteTestInfo(d4, &noOfTests);

			//testInfo files
			FILE *f8;
			f8=fopen("testInfo.txt", "w");

			fprintf(f8,"%d\n\n", noOfTests);
			
			for(int i=0;i<noOfTests;i++)
			{
				fprintf(f8,"%s || %s || %d || %d || %d || %s || %s ||\n",d4[i].testName,d4[i].testType,d4[i].testCharges,d4[i].totalMarks,d4[i].passingMarks,d4[i].testDate,d4[i].lastDateToApply);
			
			}

			fclose(f8);
			}
			break;
	

			case 6:
			feeChecker(d4, &noOfTests);
			break;

			case 7:
			testDateChecker(d4, &noOfTests);
			break;

			case 8:
			testLastDateChecker(d4, &noOfTests);
			break;

			case 9:
			shutdownTestInfoMenu();
			break;
            
			default:
			printf("You entered an invalid choice!!\a");
			
		}
	} 
	break;
			}

			else if(choiceAtMainMenu=='5')
			{
				while(choice5!=0)
				{
					printf("\n\nPress 1 to assign duty\nPress 0 to Exit\n\n");
					scanf("%d",&choice5);

					switch (choice5)
					{
					case 0:
					break;

					case 1:
					report1(d2,d3,&testCenterSize,&employeSize);
					break;
					
					default:
					printf("\n\nINVALID CHOICE!!");
					break;
					}
				}
				
			}

	else
	{
	printf("You entered invalid choice!!\a");
	}

		}

		
		
			

							

	return 0;
}
//End of the program