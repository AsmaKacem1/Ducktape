/*
MIT License

Copyright (c) 2022 Ducktape

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <math.h>
#include <stdexcept>
#include <cstring>
#include <optional>
#include <set>
#include <fstream>
#include <mutex>
#include <array>
#include <chrono>
#include <unordered_map>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <stbimage/stb_image.h>

#include <objloader/objloader.h>

#include <Rendering/Vertex.h>
#include <Core/Configuration.h>
#include <Core/Console.h>
#include <Core/AssetManager.h>

namespace Ducktape
{
    namespace Window
    {
        // Variables
        extern const int MAX_FRAMES_IN_FLIGHT;

        extern const std::vector<const char *> validationLayers;

        extern const std::vector<const char *> deviceExtensions;

        extern const bool enableValidationLayers;

        inline GLFWwindow *window;

        inline VkInstance instance;
        inline VkDebugUtilsMessengerEXT debugMessenger;
        inline VkSurfaceKHR surface;

        extern VkPhysicalDevice physicalDevice;
        inline VkDevice device;

        inline VkQueue graphicsQueue;
        inline VkQueue presentQueue;

        inline VkSwapchainKHR swapChain;
        inline std::vector<VkImage> swapChainImages;
        inline VkFormat swapChainImageFormat;
        inline VkExtent2D swapChainExtent;
        inline std::vector<VkImageView> swapChainImageViews;
        inline std::vector<VkFramebuffer> swapChainFramebuffers;

        inline VkRenderPass renderPass;
        inline VkDescriptorSetLayout descriptorSetLayout;
        inline VkPipelineLayout pipelineLayout;
        inline VkPipeline graphicsPipeline;

        inline VkCommandPool commandPool;
        inline std::vector<VkCommandBuffer> commandBuffers;

        inline std::vector<VkSemaphore> imageAvailableSemaphores;
        inline std::vector<VkSemaphore> renderFinishedSemaphores;
        inline std::vector<VkFence> inFlightFences;
        extern uint32_t currentFrame;

        extern bool framebufferResized;

        inline std::vector<Vertex> vertices;

        inline std::vector<uint32_t> indices;

        inline VkBuffer vertexBuffer;
        inline VkDeviceMemory vertexBufferMemory;
        inline VkBuffer indexBuffer;
        inline VkDeviceMemory indexBufferMemory;
        inline std::vector<VkBuffer> uniformBuffers;
        inline std::vector<VkDeviceMemory> uniformBuffersMemory;

        inline VkDescriptorPool descriptorPool;
        inline std::vector<VkDescriptorSet> descriptorSets;

        inline uint32_t mipLevels;
        inline VkImage textureImage;
        inline VkDeviceMemory textureImageMemory;
        inline VkImageView textureImageView;
        inline VkSampler textureSampler;

        inline VkImage depthImage;
        inline VkDeviceMemory depthImageMemory;
        inline VkImageView depthImageView;

        extern const std::string MODEL_PATH;
        extern const std::string TEXTURE_PATH;

        extern VkSampleCountFlagBits msaaSamples;

        inline VkImage colorImage;
        inline VkDeviceMemory colorImageMemory;
        inline VkImageView colorImageView;

        // Structs
        struct UniformBufferObject
        {
            glm::mat4 model;
            glm::mat4 view;
            glm::mat4 proj;
        };

        struct QueueFamilyIndices
        {
            std::optional<uint32_t> graphicsFamily;
            std::optional<uint32_t> presentFamily;

            bool IsComplete();
        };

        struct SwapChainSupportDetails
        {
            VkSurfaceCapabilitiesKHR capabilities;
            std::vector<VkSurfaceFormatKHR> formats;
            std::vector<VkPresentModeKHR> presentModes;
        };

        // Functions
        void LoadModel();
        VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT *pCreateInfo, const VkAllocationCallbacks *pAllocator, VkDebugUtilsMessengerEXT *pDebugMessenger);
        void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks *pAllocator);
        void Init();
        void InitWindow();
        void FramebufferResizeCallback(GLFWwindow *window, int width, int height);
        void InitVulkan();
        void CreateTextureImage();
        void CleanupSwapChain();
        void Cleanup();
        void RecreateSwapChain();
        void CreateInstance();
        void PopulateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT &createInfo);
        void SetupDebugMessenger();
        void CreateSurface();
        void PickPhysicalDevice();
        void CreateLogicalDevice();
        void CreateSwapChain();
        VkImageView CreateImageView(VkImage image, VkFormat format);
        void CreateImageViews();
        void CreateRenderPass();
        void CreateGraphicsPipeline();
        void CreateFramebuffers();
        void CreateCommandPool();
        void CreateBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer &buffer, VkDeviceMemory &bufferMemory);
        void CreateVertexBuffer();
        void CreateIndexBuffer();
        void CreateCommandBuffers();
        void RecordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);
        void CreateSyncObjects();
        void DrawFrame();
        VkSurfaceFormatKHR ChooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR> &availableFormats);
        VkPresentModeKHR ChooseSwapPresentMode(const std::vector<VkPresentModeKHR> &availablePresentModes);
        VkExtent2D ChooseSwapExtent(const VkSurfaceCapabilitiesKHR &capabilities);
        SwapChainSupportDetails QuerySwapChainSupport(VkPhysicalDevice device);
        bool IsDeviceSuitable(VkPhysicalDevice device);
        bool CheckDeviceExtensionSupport(VkPhysicalDevice device);
        QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);
        std::vector<const char *> GetRequiredExtensions();
        bool CheckValidationLayerSupport();
        VKAPI_ATTR VkBool32 VKAPI_CALL DebugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT *pCallbackData, void *pUserData);
        uint32_t FindMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);
        void CopyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);
        void CreateDescriptorSetLayout();
        void CreateUniformBuffers();
        void UpdateUniformBuffer(uint32_t currentImage);
        void CreateDescriptorPool();
        void CreateDescriptorSets();
        VkCommandBuffer BeginSingleTimeCommands();
        void EndSingleTimeCommands(VkCommandBuffer commandBuffer);
        void TransitionImageLayout(VkImage image, VkFormat format, VkImageLayout oldLayout, VkImageLayout newLayout, uint32_t mipLevels);
        void CopyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width, uint32_t height);
        void CreateImage(uint32_t width, uint32_t height, uint32_t mipLevels, VkSampleCountFlagBits numSamples, VkFormat format, VkImageTiling tiling, VkImageUsageFlags usage, VkMemoryPropertyFlags properties, VkImage &image, VkDeviceMemory &imageMemory);
        VkShaderModule CreateShaderModule(const std::vector<char> &code);
        void CreateTextureImageView();
        VkImageView CreateImageView(VkImage image, VkFormat format, VkImageAspectFlags aspectFlags, uint32_t mipLevels);
        void CreateTextureSampler();
        void CreateDepthResources();
        VkFormat FindSupportedFormat(const std::vector<VkFormat> &candidates, VkImageTiling tiling, VkFormatFeatureFlags features);
        VkFormat FindDepthFormat();
        bool HasStencilComponent(VkFormat format);
        void GenerateMipmaps(VkImage image, VkFormat format, int32_t texWidth, int32_t texHeight, uint32_t mipLevels);
        VkSampleCountFlagBits GetMaxUsableSampleCount();
        void CreateColorResources();
    }
}