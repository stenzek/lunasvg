/*
 * Copyright (c) 2020 Nwutobo Samuel Ugochukwu <sammycageagle@gmail.com>
 * Copyright (c) 2024 Connor McLaughlin <stenzek@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "lunasvg_c.h"

using namespace lunasvg;

lunasvg_box* lunasvg_box_create()
{
  return new Box();
}

lunasvg_box* lunasvg_box_create_with_values(double x, double y, double w, double h)
{
  return new Box(x, y, w, h);
}

lunasvg_box* lunasvg_box_create_from_rect(const lunasvg_box* rect)
{
  return new Box(*rect);
}

void lunasvg_box_destroy(lunasvg_box* box)
{
  delete box;
}

void lunasvg_box_transform(lunasvg_box* box, const lunasvg_matrix* matrix)
{
  box->transform(*matrix);
}

lunasvg_box* lunasvg_box_transformed(const lunasvg_box* box, const lunasvg_matrix* matrix)
{
  return new Box(box->transformed(*matrix));
}

void lunasvg_box_get_values(const lunasvg_box* box, double* x, double* y, double* w, double* h)
{
  *x = box->x;
  *y = box->y;
  *w = box->w;
  *h = box->h;
}

double lunasvg_box_get_x(const lunasvg_box* box)
{
  return box->x;
}

double lunasvg_box_get_y(const lunasvg_box* box)
{
  return box->y;
}

double lunasvg_box_get_width(const lunasvg_box* box)
{
  return box->w;
}

double lunasvg_box_get_height(const lunasvg_box* box)
{
  return box->h;
}

void lunasvg_box_set_x(lunasvg_box* box, double x)
{
  box->x = x;
}

void lunasvg_box_set_y(lunasvg_box* box, double y)
{
  box->y = y;
}

void lunasvg_box_set_width(lunasvg_box* box, double width)
{
  box->w = width;
}

void lunasvg_box_set_height(lunasvg_box* box, double height)
{
  box->h = height;
}

lunasvg_matrix* lunasvg_matrix_create()
{
  return new Matrix();
}

lunasvg_matrix* lunasvg_matrix_create_with_values(double a, double b, double c, double d, double e, double f)
{
  return new Matrix(a, b, c, d, e, f);
}

void lunasvg_matrix_destroy(lunasvg_matrix* matrix)
{
  delete matrix;
}

void lunasvg_matrix_rotate(lunasvg_matrix* matrix, double angle)
{
  matrix->rotate(angle);
}

void lunasvg_matrix_rotate_around_point(lunasvg_matrix* matrix, double angle, double cx, double cy)
{
  matrix->rotate(angle, cx, cy);
}

void lunasvg_matrix_scale(lunasvg_matrix* matrix, double sx, double sy)
{
  matrix->scale(sx, sy);
}

void lunasvg_matrix_shear(lunasvg_matrix* matrix, double shx, double shy)
{
  matrix->shear(shx, shy);
}

void lunasvg_matrix_translate(lunasvg_matrix* matrix, double tx, double ty)
{
  matrix->translate(tx, ty);
}

void lunasvg_matrix_transform(lunasvg_matrix* matrix, double a, double b, double c, double d, double e, double f)
{
  matrix->transform(a, b, c, d, e, f);
}

void lunasvg_matrix_identity(lunasvg_matrix* matrix)
{
  matrix->identity();
}

void lunasvg_matrix_invert(lunasvg_matrix* matrix)
{
  matrix->invert();
}

void lunasvg_matrix_multiply(lunasvg_matrix* matrix, const lunasvg_matrix* rhs)
{
  *matrix *= *rhs;
}

void lunasvg_matrix_premultiply(lunasvg_matrix* matrix, const lunasvg_matrix* rhs)
{
  matrix->premultiply(*rhs);
}

void lunasvg_matrix_postmultiply(lunasvg_matrix* matrix, const lunasvg_matrix* rhs)
{
  matrix->postmultiply(*rhs);
}

lunasvg_matrix* lunasvg_matrix_inverted(const lunasvg_matrix* matrix)
{
  return new Matrix(matrix->inverted());
}

lunasvg_matrix* lunasvg_matrix_rotated(double angle)
{
  return new Matrix(Matrix::rotated(angle));
}

lunasvg_matrix* lunasvg_matrix_rotated_around_point(double angle, double cx, double cy)
{
  return new Matrix(Matrix::rotated(angle, cx, cy));
}

lunasvg_matrix* lunasvg_matrix_scaled(double sx, double sy)
{
  return new Matrix(Matrix::scaled(sx, sy));
}

lunasvg_matrix* lunasvg_matrix_sheared(double shx, double shy)
{
  return new Matrix(Matrix::sheared(shx, shy));
}

lunasvg_matrix* lunasvg_matrix_translated(double tx, double ty)
{
  return new Matrix(Matrix::translated(tx, ty));
}

void lunasvg_matrix_get_values(const lunasvg_matrix* matrix, double* a, double* b, double* c, double* d, double* e,
                               double* f)
{
  *a = matrix->a;
  *b = matrix->b;
  *c = matrix->c;
  *d = matrix->d;
  *e = matrix->e;
  *f = matrix->f;
}

lunasvg_bitmap* lunasvg_bitmap_create()
{
  return new Bitmap();
}

lunasvg_bitmap* lunasvg_bitmap_create_with_data(uint8_t* data, uint32_t width, uint32_t height, uint32_t stride)
{
  return new Bitmap(data, width, height, stride);
}

lunasvg_bitmap* lunasvg_bitmap_create_with_size(uint32_t width, uint32_t height)
{
  return new Bitmap(width, height);
}

void lunasvg_bitmap_destroy(lunasvg_bitmap* bitmap)
{
  delete bitmap;
}

void lunasvg_bitmap_reset_with_data(lunasvg_bitmap* bitmap, uint8_t* data, uint32_t width, uint32_t height,
                                    uint32_t stride)
{
  bitmap->reset(data, width, height, stride);
}

void lunasvg_bitmap_reset_with_size(lunasvg_bitmap* bitmap, uint32_t width, uint32_t height)
{
  bitmap->reset(width, height);
}

uint8_t* lunasvg_bitmap_data(const lunasvg_bitmap* bitmap)
{
  return bitmap->data();
}

uint32_t lunasvg_bitmap_width(const lunasvg_bitmap* bitmap)
{
  return bitmap->width();
}

uint32_t lunasvg_bitmap_height(const lunasvg_bitmap* bitmap)
{
  return bitmap->height();
}

uint32_t lunasvg_bitmap_stride(const lunasvg_bitmap* bitmap)
{
  return bitmap->stride();
}

void lunasvg_bitmap_clear(lunasvg_bitmap* bitmap, uint32_t color)
{
  bitmap->clear(color);
}

void lunasvg_bitmap_convert(lunasvg_bitmap* bitmap, int ri, int gi, int bi, int ai, int unpremultiply)
{
  bitmap->convert(ri, gi, bi, ai, unpremultiply);
}

void lunasvg_bitmap_convert_to_rgba(lunasvg_bitmap* bitmap)
{
  bitmap->convertToRGBA();
}

bool lunasvg_bitmap_valid(const lunasvg_bitmap* bitmap)
{
  return bitmap->valid();
}

lunasvg_document* lunasvg_document_load_from_file(const char* filename)
{
  return Document::loadFromFile(filename).release();
}

lunasvg_document* lunasvg_document_load_from_data(const void* data, size_t size)
{
  return Document::loadFromData(static_cast<const char*>(data), size).release();
}

lunasvg_document* lunasvg_document_load_from_string(const char* data)
{
  return Document::loadFromData(data).release();
}

void lunasvg_document_destroy(lunasvg_document* document)
{
  delete document;
}

void lunasvg_document_set_matrix(lunasvg_document* document, const lunasvg_matrix* matrix)
{
  document->setMatrix(*matrix);
}

void lunasvg_document_set_identity_matrix(lunasvg_document* document)
{
  document->setMatrix(Matrix().identity());
}

void lunasvg_document_get_matrix(const lunasvg_document* document, lunasvg_matrix* matrix)
{
  *matrix = document->matrix();
}

void lunasvg_document_get_box(const lunasvg_document* document, lunasvg_box* box)
{
  *box = document->box();
}

double lunasvg_document_get_width(const lunasvg_document* document)
{
  return document->width();
}

double lunasvg_document_get_height(const lunasvg_document* document)
{
  return document->height();
}

void lunasvg_document_render(const lunasvg_document* document, lunasvg_bitmap* bitmap, const lunasvg_matrix* matrix)
{
  document->render(*bitmap, *matrix);
}

lunasvg_bitmap* lunasvg_document_render_to_bitmap(const lunasvg_document* document, uint32_t width, uint32_t height,
                                                  uint32_t background_color)
{
  return new Bitmap(document->renderToBitmap(width, height, background_color));
}

void lunasvg_document_update_layout(lunasvg_document* document)
{
  document->updateLayout();
}
