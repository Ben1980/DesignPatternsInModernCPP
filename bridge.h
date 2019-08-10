#include <iostream>
#include <string>
#include <sstream>

// Decoupling abstraction from implementation and therefore can help enforceing encapsulation
struct Renderer
{
  virtual string what_to_render_as() const = 0;
};

struct Shape
{
  std::string name;
  const Renderer& renderer;

  Shape(const Renderer& renderer): renderer{renderer} {
  }

  std::string str() const
  {
    std::ostringstream oss;
    oss << "Drawing " << name << " as "
      << renderer.what_to_render_as();
    return oss.str();
  }
};

struct Triangle : Shape
{
  explicit Triangle(const Renderer& renderer)
    : Shape{renderer}
  {
    name = "Triangle";
  }
};

struct Square : Shape
{
  explicit Square(const Renderer& renderer)
    : Shape{renderer}
  {
    name = "Square";
  }
};

struct RasterRenderer : Renderer
{
  string what_to_render_as() const override
  {
    return "pixels";
  }
};

struct VectorRenderer : Renderer
{
  string what_to_render_as() const override
  {
    return "lines";
  }
};
