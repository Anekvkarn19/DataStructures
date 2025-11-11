#include <iostream>
using namespace std;

// Structure for a term in the polynomial
struct Node {
    int coeff;  // Coefficient
    int pow;    // Power
    Node* next;
};

// Function to create a new node
Node* createNode(int coeff, int pow) {
    Node* newNode = new Node;
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = nullptr;
    return newNode;
}

// Insert node in descending order of power
void insertNode(Node*& head, int coeff, int pow) {
    Node* newNode = createNode(coeff, pow);

    // If list is empty or head has smaller power
    if (!head || head->pow < pow) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;

    // Traverse until correct position found
    while (temp && temp->pow > pow) {
        prev = temp;
        temp = temp->next;
    }

    // If power already exists, update coefficient
    if (temp && temp->pow == pow) {
        temp->coeff += coeff;
        delete newNode;  // avoid memory leak
    } else {
        if (prev) {
            newNode->next = temp;
            prev->next = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }
}

// Add two polynomials
Node* addPolynomial(Node* poly1, Node* poly2) {
    Node* result = nullptr;

    while (poly1 && poly2) {
        if (poly1->pow == poly2->pow) {
            insertNode(result, poly1->coeff + poly2->coeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } 
        else if (poly1->pow > poly2->pow) {
            insertNode(result, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        } 
        else {
            insertNode(result, poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        }
    }

    while (poly1) {
        insertNode(result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }

    while (poly2) {
        insertNode(result, poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }

    return result;
}

// Subtract two polynomials (poly1 - poly2)
Node* subtractPolynomial(Node* poly1, Node* poly2) {
    Node* result = nullptr;

    while (poly1 && poly2) {
        if (poly1->pow == poly2->pow) {
            insertNode(result, poly1->coeff - poly2->coeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } 
        else if (poly1->pow > poly2->pow) {
            insertNode(result, poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        } 
        else {
            insertNode(result, -poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        }
    }

    while (poly1) {
        insertNode(result, poly1->coeff, poly1->pow);
        poly1 = poly1->next;
    }

    while (poly2) {
        insertNode(result, -poly2->coeff, poly2->pow);
        poly2 = poly2->next;
    }

    return result;
}

// Multiply two polynomials
Node* multiplyPolynomial(Node* poly1, Node* poly2) {
    Node* result = nullptr;

    for (Node* p1 = poly1; p1 != nullptr; p1 = p1->next) {
        for (Node* p2 = poly2; p2 != nullptr; p2 = p2->next) {
            int coeff = p1->coeff * p2->coeff;
            int pow = p1->pow + p2->pow;
            insertNode(result, coeff, pow);
        }
    }

    return result;
}

// Display polynomial
void printPolynomial(Node* poly) {
    if (!poly) {
        cout << "0";
        return;
    }
    bool first = true;
    while (poly) {
        if (!first && poly->coeff >= 0)
            cout << " + ";
        cout << poly->coeff << "x^" << poly->pow;
        poly = poly->next;
        first = false;
    }
    cout << endl;
}

// Take user input
Node* inputPolynomial() {
    Node* poly = nullptr;
    int terms;
    cout << "Enter number of terms: ";
    cin >> terms;

    cout << "Enter each term (coefficient and power):\n";
    for (int i = 0; i < terms; i++) {
        int coeff, pow;
        cout << "Term " << i + 1 << " - Coeff: ";
        cin >> coeff;
        cout << "          Power: ";
        cin >> pow;
        insertNode(poly, coeff, pow);
    }
    return poly;
}

// Main function
int main() {
    cout << "--- Polynomial Operations using Linked List ---\n\n";

    cout << "Enter first polynomial:\n";
    Node* poly1 = inputPolynomial();

    cout << "\nEnter second polynomial:\n";
    Node* poly2 = inputPolynomial();

    cout << "\nFirst Polynomial: ";
    printPolynomial(poly1);

    cout << "Second Polynomial: ";
    printPolynomial(poly2);

    Node* sum = addPolynomial(poly1, poly2);
    Node* diff = subtractPolynomial(poly1, poly2);
    Node* prod = multiplyPolynomial(poly1, poly2);

    cout << "\nSum of Polynomials: ";
    printPolynomial(sum);

    cout << "Difference of Polynomials (P1 - P2): ";
    printPolynomial(diff);

    cout << "Product of Polynomials: ";
    printPolynomial(prod);

    return 0;
}
