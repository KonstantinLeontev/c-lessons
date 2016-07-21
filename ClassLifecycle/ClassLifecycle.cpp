enum ChessPiece {EMPTY_SQUARE, WHITE_PAWN};
enum PlayColor {PC_WHITE, PC_BLACK};

class ChessBoard
{
public:
	chessBoard();
	chessBoard(int board_size);
	PlayerColor getMove();
	ChessPiece getPiece(int x, int y);
	void makeMove(int from_x, int from_y, int to_x, int to_y);

private:
	ChessPiece board[8][8];
	PlayerColor whoseMove;
	int moveCount;
};

ChessBoard::chessBoard()
{
	whose_move = PC_WHITE;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j] = EMPTY_SQUARE;
		}
	}
}

ChessBoard::chessBoard(int board_size)
	: whoseMove(PC_WHITE), moveCount(0)
{

}

ChessBoard *pBoard = new ChessBoard(8);

class LinkedListNode
{
	~LinkedListNode();
	int val;
	LinkedListNode *pNext;
};

class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	LinkedList &operator= (const LinkedList &other);
	LinkedList(const LinkedList &other);
	void insert(int val);

private:
	LinkedListNode *pHead;
};

LinkedList::~LinkedList()
{
	LinkedListNode *pItr = pHead;
	while (pItr != NULL)
	{
		LinkedListNode *pTemp = pItr->pNext;
		delete pItr;
		pItr = pTemp;
	}
}

LinkedListNode::~LinkedListNode()
{
	delete pNext;
}

LinkedList::~LinkedList()
{
	delete pHead;
}

LinkedList& LinkedList::operator= (const LinkedList& other)
{
	if (this == &other)
	{
		return *this;
	}
	delete pHead;
	pHead = NULL;

	LinkedListNode *pItr = other.pHead;
	while (pItr != NULL)
	{
		insert(pItr->val);
	}
	return *this;
}

LinkedList::LinkedList(const LinkedList &other)
	: pHead (NULL)
{
	LinkedListNode *pItr = other.pHead;
	while (pItr != NULL)
	{
		insert(pItr->val);
	}
}