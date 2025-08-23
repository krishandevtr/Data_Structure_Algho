 struct Node{
    int data;
    Node *pointer ;
}*head;

void deleteNode(Node*& head, int key) {
    if (head == nullptr) return;

    if (head->data == key) {
        Node* temp = head;
        head = head->pointer;
        delete temp;
        return;
    }

    Node* prev = head;
    Node* curr = head->pointer;

    while (curr != nullptr) {
        if (curr->data == key) {
            prev->pointer = curr->pointer;
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->pointer;
    }

}
