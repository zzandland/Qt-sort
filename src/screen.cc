#include "screen.h"

#include "diagram/line.h"

Screen::Screen(SDL_Renderer* renderer, const Uint32 width, const Uint32 height,
               const Uint32 size)
    : renderer_(renderer), width_(width), height_(height), size_(size) {
  diagram_ = new Line(renderer, size, width, height);
}

Screen::~Screen() {
  delete diagram_;
  SDL_DestroyRenderer(renderer_);
  renderer_ = nullptr;
}

void Screen::set_size(const Uint32 size) {
  size_ = size;
  Init();
}

void Screen::Init() {
  SDL_SetRenderDrawColor(renderer_, 0, 0, 0, SDL_ALPHA_TRANSPARENT);
  SDL_RenderClear(renderer_);
  diagram_->Init(renderer_, size_, width_, height_);
}

void Screen::Render() { diagram_->Render(renderer_); }

void Screen::Update(std::vector<Uint32>& data, std::vector<size_t>& indexes,
                    SDL_Color color) {
  diagram_->Update(renderer_, data, indexes, color);
}

void Screen::Update(std::vector<Uint32>& data, size_t index, SDL_Color color) {
  diagram_->Update(renderer_, data, index, color);
}
