#include <stdio.h>
#include <string.h>


//CREATING CANDIDATE STRUCTURE
struct candidate{
    int candidateID;
    int numVotes;
    char candidateName[50];
    char organization[50];
};

//CREATING ADMIN STRUCTURE
struct admin{
    int adminID;
    char adminName[50];
};

int main() {

    //VARIABLE DECLARATION
    int userType;
    int passwordEntry;
    int voterPass = 1234;
    int adminPass = 123456789;
    int adminList;
    int candidateList;
    int voteFor;

    //CREATING AN ADMIN
    struct admin admin1;
    admin1.adminID = 100;
    strcpy(admin1.adminName, "Sydney Peters");

    //CREATING CANDIDATES
    struct candidate candidate1, candidate2, candidate3, candidate4, candidate5;
    candidate1.candidateID = 1;
    candidate1.numVotes = 0;
    strcpy(candidate1.candidateName, "Bob Belcher");
    strcpy(candidate1.organization, "Bobs Burgers");

    candidate2.candidateID = 2;
    candidate2.numVotes = 0;
    strcpy(candidate2.candidateName, "Spongebob");
    strcpy(candidate2.organization, "Krusty Krab");

    candidate3.candidateID = 3;
    candidate3.numVotes = 0;
    strcpy(candidate3.candidateName, "Remy");
    strcpy(candidate3.organization, "Gusteau's");

    candidate4.candidateID = 4;
    candidate4.numVotes = 0;
    strcpy(candidate4.candidateName, "");
    strcpy(candidate4.organization, "");

    candidate5.candidateID = 5;
    candidate5.numVotes = 0;
    strcpy(candidate5.candidateName, "");
    strcpy(candidate5.organization, "");


    //USER TYPE SELECTION
    userTypeSelect:
    printf("Welcome to the Polling Application!\n");
    printf("-------------------------------------------------\n");
    printf("Are you a Voter or an Administrator?\n");
    printf("Type '1' for Voter or '2' for Administrator and press [ENTER]\n");
    scanf("%d", &userType);

    //VOTER LOGIN
    voterLogin:
    if(userType==1){
        printf("Welcome to Voter Login!\n");
        printf("-------------------------------------------------\n");
        printf("Please enter the provided Voter Password: \n");
        scanf("%d", &passwordEntry);
        //VALID VOTER LOGIN
        if(passwordEntry==voterPass){
            printf("Login Successful! Welcome Voter!\n");
            printf("-------------------------------------------------\n");

            //CASTING VOTES
            printf("CANDIDATES:\n");
                printf("Name: %s\n", candidate1.candidateName);
                printf("Organization: %s\n", candidate1.organization);
                printf("-------------------------------------------------\n");
                printf("Name: %s\n", candidate2.candidateName);
                printf("Organization: %s\n", candidate2.organization);
                printf("-------------------------------------------------\n");
                printf("Name: %s\n", candidate3.candidateName);
                printf("Organization: %s\n", candidate3.organization);
                printf("-------------------------------------------------\n");

                printf("VOTING TIME!\n");
                printf("To cast your vote, type the number associated with your favorite candidate and press[ENTER]\n");
                printf("1. %s\n", candidate1.candidateName);
                printf("2. %s\n", candidate2.candidateName);
                printf("3. %s\n", candidate3.candidateName);
//                printf("4. %s\n", candidate4.candidateName);
//                printf("5. %s\n", candidate5.candidateName);
                scanf("%d", &voteFor);
                if(voteFor==1){
                    printf("You voted for %s", candidate1.candidateName);
                    printf(" who works at %s\n", candidate1.organization);
                    candidate1.numVotes = ++candidate1.numVotes;
                }
                else if(voteFor==2){
                    printf("You voted for %s", candidate2.candidateName);
                    printf(" who works at %s\n", candidate2.organization);
                    candidate2.numVotes = ++candidate2.numVotes;
                }
                else if(voteFor==3){
                    printf("You voted for %s", candidate3.candidateName);
                    printf(" who works at %s\n", candidate3.organization);
                    candidate3.numVotes = ++candidate3.numVotes;
                }
                else if(voteFor==4){
                    printf("You voted for %s", candidate4.candidateName);
                    printf(" who works at %s\n", candidate4.organization);
                    candidate3.numVotes = ++candidate4.numVotes;
                }
                else if(voteFor==5){
                    printf("You voted for %s", candidate4.candidateName);
                    printf(" who works at %s\n", candidate4.organization);
                    candidate3.numVotes = ++candidate4.numVotes;
                }
                //INVALID CANDIDATE NUMBER
                else{
                    printf("You did not enter any number associated with the current candidates\n");
                    goto voterLogin;
                }

        }
        //INVALID VOTER PASSWORD
        else{
            printf("You entered the wrong password.\n");
            printf("-------------------------------------------------\n");
            goto voterLogin;
        }
    }
    //ADMIN LOGIN
    else if(userType==2){
        printf("Welcome to Admin Login!\n");
        printf("-------------------------------------------------\n");
        adminPass:
        printf("Please enter your password:\n");
        scanf("%d", &passwordEntry);

        //VALID ADMIN LOGIN

        if(passwordEntry==adminPass) {
            printf("Welcome, Administrator!\n");
            adminList:
            printf("-------------------------------------------------\n");
            printf("What would you like to do? Type the number of the action you would like to complete and press [ENTER]\n");
            printf("1. Edit Voter Password\n");
            printf("2. Edit Candidate Information\n");
            printf("3. See all Candidate Information\n");
            printf("4. See voting results\n");
            scanf("%d", &adminList);
            if (adminList == 1) {
                printf("You selected 'Edit Voter Password'\n");
                printf("-------------------------------------------------\n");
                printf("Type any sequence of numbers to set as the new Voter Password and press [ENTER]\n");
                scanf("%d", &voterPass);
                printf("The new Voter Password is: %d\n", voterPass);
                goto adminList;
            } else if (adminList == 2) {
                adminList2:
                printf("You selected 'Edit Candidate Information'\n");
                printf("-------------------------------------------------\n");
                printf("Type the number of the candidate you would like to edit and press [ENTER]\n");
                printf("1. Candidate 1\n");
                printf("2. Candidate 2\n");
                printf("3. Candidate 3\n");
                printf("4. Candidate 4\n");
                printf("5. Candidate 5\n");
                scanf("%d", &candidateList);

                if (candidateList == 1) {
                    printf("Type the name of the candidate:\n");
                    scanf("%s", &candidate1.candidateName);
                    printf("The new name for Candidate 1: %s\n", candidate1.candidateName);
                    printf("-------------------------------------------------\n");
                    printf("Type the name of the candidate's organization:\n");
                    scanf("%s", &candidate1.organization);
                    printf("The candidate's organization has been set to %s\n", candidate1.organization);
                } else if (candidateList == 2) {
                    printf("Type the name of the candidate:\n");
                    scanf("%s", &candidate2.candidateName);
                    printf("The new name for Candidate 2: %s\n", candidate2.candidateName);
                    printf("-------------------------------------------------\n");
                    printf("Type the name of the candidate's organization:\n");
                    scanf("%s", &candidate2.organization);
                    printf("The candidate's organization has been set to %s\n", candidate2.organization);
                } else if (candidateList == 3) {
                    printf("Type the name of the candidate:\n");
                    scanf("%s", &candidate3.candidateName);
                    printf("The new name for Candidate 3: %s\n", candidate3.candidateName);
                    printf("-------------------------------------------------\n");
                    printf("Type the name of the candidate's organization:\n");
                    scanf("%s", &candidate3.organization);
                    printf("The candidate's organization has been set to %s\n", candidate3.organization);
                } else if (candidateList == 4) {
                    printf("Type the name of the candidate:\n");
                    scanf("%s", &candidate4.candidateName);
                    printf("The new name for Candidate 4: %s\n", candidate4.candidateName);
                    printf("-------------------------------------------------\n");
                    printf("Type the name of the candidate's organization:\n");
                    scanf("%s", &candidate4.organization);
                    printf("The candidate's organization has been set to %s\n", candidate4.organization);
                } else if (candidateList == 5) {
                    printf("Type the name of the candidate:\n");
                    scanf("%s", &candidate5.candidateName);
                    printf("The new name for Candidate 5: %s\n", candidate5.candidateName);
                    printf("-------------------------------------------------\n");
                    printf("Type the name of the candidate's organization:\n");
                    scanf("%s", &candidate5.organization);
                    printf("The candidate's organization has been set to %s\n", candidate5.organization);
                }
                    //INVALID ADMIN LIST NUMBER
                else {
                    printf("You did not enter a valid candidate number.");
                    goto adminList2;
                }
            } else if (adminList == 3) {
                printf("You selected 'See all Candidate Information'\n");
                printf("-------------------------------------------------\n");
                //PRINTS CANDIDATE INFORMATION TO PANEL
                printf("ID: %d\n", candidate1.candidateID);
                printf("Name: %s\n", candidate1.candidateName);
                printf("Organization: %s\n", candidate1.organization);
                printf("-------------------------------------------------\n");

                printf("ID: %d\n", candidate2.candidateID);
                printf("Name: %s\n", candidate2.candidateName);
                printf("Organization: %s\n", candidate2.organization);
                printf("-------------------------------------------------\n");

                printf("ID: %d\n", candidate3.candidateID);
                printf("Name: %s\n", candidate3.candidateName);
                printf("Organization: %s\n", candidate3.organization);
                printf("-------------------------------------------------\n");

                printf("ID: %d\n", candidate4.candidateID);
                printf("Name: %s\n", candidate4.candidateName);
                printf("Organization: %s\n", candidate4.organization);
                printf("-------------------------------------------------\n");

                printf("ID: %d\n", candidate5.candidateID);
                printf("Name: %s\n", candidate5.candidateName);
                printf("Organization: %s\n", candidate5.organization);
                printf("-------------------------------------------------\n");
                goto adminList;
            } else if (adminList == 4) {
                printf("You selected 'See voting results'\n");
                printf("-------------------------------------------------\n");
                printf("Candidate 1 has %d", candidate1.numVotes);
                printf(" votes\n");
                printf("Candidate 2 has %d", candidate2.numVotes);
                printf(" votes\n");
                printf("Candidate 3 has %d", candidate3.numVotes);
                printf(" votes\n");
                printf("Candidate 4 has %d", candidate4.numVotes);
                printf(" votes\n");
                printf("Candidate 5 has %d", candidate5.numVotes);
                printf(" votes\n");
                goto adminList;
            }
                //INVALID CANDIDATE NUMBER
            else {
                printf("You did not enter a number in the list.\n");
                goto adminList;
            }
        }
        //INVALID ADMIN LOGIN
        else{
            printf("You entered your password wrong.");
           goto adminPass;
        }
    }
    //INVALID USER TYPE
    else{
        printf("You did not enter the number 1 or 2.");
        goto userTypeSelect;
    }




    return 0;
}
