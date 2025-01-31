#include <stdio.h>
#include <conio.h>
#include <windows.h>

struct candidate {
    const char name[10];
    int votes;
    float percentage;
};

void get_votes(struct candidate *candidates, int total) {
    int i, choice;
    for (i = 0; i < total; i++) {
        printf("\n\t\t<--------------------------WELCOME TO GROUP 8 VOTING SYSTEM--------------------->\t\t");
        printf("\n Enter 1 to vote for PRATIK");
        printf("\n Enter 2 to vote for RITIK");
        printf("\n Enter 3 to vote for DIBYA");
        printf("\n Enter 4 to vote for SAI SUBHAM");

        printf("\n \n Enter your choice  : ");
  
        if (choice >= 1 && choice <= 4) {
            candidates[choice - 1].votes++;
            printf("\n Thank you for giving vote on our system", candidates[choice - 1].name);
        } else {
            candidates[4].votes++;
            printf("\n Thank you for voting for None");
        }
    }
}

void print_results(struct candidate *candidates, int total) {
    int max_votes = 0, min_votes = total;
    int i, winner_count = 0;

    for (i = 0; i < 4; i++) {
        if (candidates[i].votes > max_votes) {
            max_votes = candidates[i].votes;
        }
        if (candidates[i].votes < min_votes) {
            min_votes = candidates[i].votes;
        }
        candidates[i].percentage = (float)candidates[i].votes / total * 100;
    }

    for (i = 0; i < 4; i++) {
        if (candidates[i].votes == max_votes) {
            winner_count++;
        }
    }

    if (winner_count == 1) {
        for (i = 0; i < 4; i++) {
            if (candidates[i].votes == max_votes) {
                printf("\n The winner is %s with %d votes and (%.2f%%)percentage ", candidates[i].name, candidates[i].votes, candidates[i].percentage);
                break;
            }
        }
    } 
    else {
        printf("\n There is a tie between the these candidates:");
        for (i = 0; i < 4; i++) {
            if (candidates[i].votes == max_votes) {
                printf("\n %s with %d votes (%.2f%%) ", candidates[i].name, candidates[i].votes, candidates[i].percentage);
            }
        }
    }

    for (i = 0; i < 4; i++) {
        printf("\n Number of votes for %s = %d ", candidates[i].name, candidates[i].votes);
    }
    printf("\n Number of votes for None = %d", candidates[4].votes);
}

int main() {
    system("color 0c");
    struct candidate candidates[5] = {{"A", 0}, {"B", 0}, {"C", 0}, {"D", 0}, {"NONE", 0}};
    
    int TOTAL_VOTE;

    printf("Enter the number of voters : ");
    scanf("%d", &TOTAL_VOTE);
    get_votes(candidates, TOTAL_VOTE);
    

    print_results(candidates, TOTAL_VOTE);

    return 0;
}

