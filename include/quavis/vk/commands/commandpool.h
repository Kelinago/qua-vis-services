#ifndef QUAVIS_COMMANDPOOL_H
#define QUAVIS_COMMANDPOOL_H

namespace quavis {
  /**
  * A wrapper around VkCommandPool providing convenience methods for beginning
  * and ending a command buffer.
  */
  class CommandPool {
  public:
    /**
    * Creates a new command pool for the given queue family
    */
    CommandPool(LogicalDevice device, uint32_t queue_family_index);

    /**
    * Safely destroys the VkCommandPool object. All dependents need to be
    * destroyed beforehand.
    */
    ~CommandPool();

    /**
    * Begins a new command buffer.
    */
    VkCommandBuffer BeginCommandBuffer(VkCommandBufferUsageFlags flags);

    /**
    * Ends a command buffer. The submission of the command buffer is the
    * responsibility of the caller.
    */
    void EndCommandBuffer(VkCommandBuffer command_buffer);

  private:
    LogicalDevice device_;
    VkCommandPool pool_;
  }
}

#endif