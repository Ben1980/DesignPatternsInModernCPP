struct Square
{
  int side{ 0 };


  explicit Square(const int side)
    : side(side)
  {
  }
};

struct Rectangle
{
  virtual int width() const = 0;
  virtual int height() const = 0;

  int area() const
  {
    return width() * height();
  }
};


// Adapt the interface of a square to the interface of a rectangle
// Example:
// Square square(2);
// SquareToRectangleAdapter adapter(square);
struct SquareToRectangleAdapter : Rectangle
{
  SquareToRectangleAdapter(const Square& square)
    : square(square) {}
  
  int width() const override
  {
    return square.side;
  }

  int height() const override
  {
    return square.side;
  }

  const Square& square;
};
