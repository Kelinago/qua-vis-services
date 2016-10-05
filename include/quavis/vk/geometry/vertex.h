#ifndef QUAVIS_VERTEX_H
#define QUAVIS_VERTEX_H

#include "quavis/vk/geometry/geometry.h"

#include <vulkan/vulkan.h>
#include <vector>

namespace quavis {
  struct Vertex {
      vec3 pos;
      vec3 color;

      static VkVertexInputBindingDescription getBindingDescription() {
          VkVertexInputBindingDescription bindingDescription = {};
          bindingDescription.binding = 0;
          bindingDescription.stride = sizeof(Vertex);
          bindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;
          return bindingDescription;
      }

      static std::vector<VkVertexInputAttributeDescription> getAttributeDescriptions() {
          std::vector<VkVertexInputAttributeDescription> attributeDescriptions(2);
          attributeDescriptions[0].binding = 0;
          attributeDescriptions[0].location = 0;
          attributeDescriptions[0].format = VK_FORMAT_R32G32B32_SFLOAT;
          attributeDescriptions[0].offset = offsetof(Vertex, pos);

          attributeDescriptions[1].binding = 0;
          attributeDescriptions[1].location = 1;
          attributeDescriptions[1].format = VK_FORMAT_R32G32B32_SFLOAT;
          attributeDescriptions[1].offset = offsetof(Vertex, color);

          return attributeDescriptions;
      }
  };
}

#endif
