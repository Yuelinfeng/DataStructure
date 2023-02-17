#include <iostream>
#include "linkList.h"
int main() {
    LinkList* link =  createLinkList();
    insertLinkList(link,1,5);
    insertLinkList(link,2);
    insertLinkList(link,3);
    insertLinkList(link,4);
    deleteLinkList(link,5);
    insertLinkList(link,2,5);
    insertLinkList(link,3,3);
    showLinkList(link);
    releaseLinkList(link);
    return 0;
}
