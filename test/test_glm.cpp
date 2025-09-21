
#include <gtest/gtest.h>

#include <glm/glm.hpp>


namespace FireOpenGL::Test {
    TEST(TestGlm, vec3) {

        glm::vec3 v(1.0f, 0.0f, 0.5f);
        ASSERT_FLOAT_EQ(v.x, 1.0f);
        ASSERT_FLOAT_EQ(v.y, 0.0f);
        ASSERT_FLOAT_EQ(v.z, 0.5f);
    }
}