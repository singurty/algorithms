package main

type ListNode struct {
	Val int
	Next *ListNode
}

func rotateRight(head *ListNode, k int) *ListNode {
	list := make([]int, 0)
	currentNode := head
	for currentNode != nil {
		list = append(list, currentNode.Val)
		currentNode = currentNode.Next
	}
	rotatedList := make([]int, len(list))
	copy(rotatedList, list[len(list)-1-k:])
	copy(rotatedList, list[:len(list)-1-k])
	currentNode = head
	for i:=0; currentNode != nil; i++ {
		currentNode.Val = rotatedList[i]
		currentNode = currentNode.Next
	}
	return head
}
