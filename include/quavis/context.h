#ifndef QUAVIS_CONTEXT_H
#define QUAVIS_CONTEXT_H

#include "quavis/version.h"
#include "quavis/shaders.h"
#include "quavis/debug.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include <vulkan/vulkan.h>
#include <stdio.h>
#include <string.h>
#include <memory>
#include <vector>
#include <set>
#include <array>

namespace quavis {
  /**
  * The Context class initializes and prepares the vulkan instance for fast
  * computations on the graphics card.
  */
  class Context {
  public:
    /**
    * Creates a new instance of the Context class. During its initialization,
    * the vulkan devices and pipelines are prepared for rendering / computation.
    */
    Context();

    /**
    * Destroy the object. All vulkan objects are cleanly removed here.
    */
    ~Context();

  private:
    void InitializeVkInstance();
    void InitializeVkPhysicalDevice();
    void InitializeVkLogicalDevice();
    void InitializeVkShaderModules();
    void InitializeVkRenderPass();
    void InitializeVkGraphicsPipeline();
    void InitializeVkGraphicsPipelineLayout();
    void InitializeVkMemory();
    void InitializeVkCommandPool();
    void InitializeVkCommandBuffers();
    void VkDraw();

    void copyImage(VkImage srcImage, VkImage dstImage, uint32_t width, uint32_t height);
    VkCommandBuffer beginSingleTimeCommands();
    void endSingleTimeCommands(VkCommandBuffer commandBuffer);
    void transitionImageLayout(VkImage image, VkImageLayout oldLayout, VkImageLayout newLayout);

    // instance data
    VkInstance vk_instance_;
    VkPhysicalDevice vk_physical_device_;
    VkDevice vk_logical_device_;
    uint32_t queue_family_index_;

    // command pool
    VkCommandPool vk_command_pool_;

    // queues
    VkQueue vk_queue_graphics_;
    VkQueue vk_queue_compute_;
    VkQueue vk_queue_transfer_;

    // shaders
    VkShaderModule vk_vertex_shader_;
    VkShaderModule vk_fragment_shader_;

    // pipeline
    VkRenderPass vk_render_pass_;
    VkPipelineLayout vk_pipeline_layout_;
    VkPipeline vk_pipeline_;

    // images
    VkImageView vk_color_imageview_;
    VkImageView vk_stencil_imageview_;
    VkImage vk_color_image_;
    VkImage vk_stencil_image_;
    VkImage vk_host_visible_image_;
    VkDeviceMemory vk_color_image_memory_;
    VkDeviceMemory vk_stencil_image_memory_;
    VkDeviceMemory vk_host_visible_image_memory_;

    // framebuffers
    VkFramebuffer vk_graphics_framebuffer_;

    // command buffers
    VkCommandBuffer vk_graphics_commandbuffer_;

    // semaphores
    VkSemaphore vk_render_semaphore_;
    VkSemaphore vk_render_finished_semaphore_;

    // meta data for initialization
    const std::vector<const char*> vk_instance_extension_names_ = {
      "VK_EXT_debug_report"
    };

    // meta data for initialization
    const std::vector<const char*> vk_logical_device_extension_names_ = {
    };

    const std::vector<const char*> vk_validation_layers_ = {
      "VK_LAYER_LUNARG_standard_validation"
    };


    // rendering attributes
    const uint32_t render_width_ = 500;
    const uint32_t render_height_ = 500;
    const VkFormat color_format_ = VK_FORMAT_R8G8B8A8_UNORM;
    const VkFormat stencil_format_ = VK_FORMAT_D32_SFLOAT_S8_UINT;
  };
}

#endif
