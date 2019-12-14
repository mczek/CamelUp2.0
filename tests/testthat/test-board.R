test_that("test board constructor", {
  b <- Board$new(19)
  expect_equal(b$getNSpaces(), 19)
})
