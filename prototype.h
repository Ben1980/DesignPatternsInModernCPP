struct Point
{
  int x{ 0 }, y{ 0 };

  Point(){}
  
  Point(const int x, const int y) : x{x}, y{y} {}
};

// Create new instances by cloning a prototype
// Example:
// Line line(new Point(), new Point(2,2));
// Line copy = line.deep_copy();
struct Line
{
  Point *start, *end;
  
  Line(Point* const start, Point* const end)
    : start(start), end(end)
  {
  }

  ~Line()
  {
    delete start;
    delete end;
  }

  Line deep_copy() const
  {
    return {new Point(start->x, start->y), 
            new Point(end->x, end->y)};
  }
};
