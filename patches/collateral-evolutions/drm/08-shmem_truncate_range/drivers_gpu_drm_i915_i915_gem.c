--- a/drivers/gpu/drm/i915/i915_gem.c
+++ b/drivers/gpu/drm/i915/i915_gem.c
@@ -1620,7 +1620,13 @@
 	 * backing pages, *now*.
 	 */
 	inode = file_inode(obj->base.filp);
+#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3,0,0))
 	shmem_truncate_range(inode, 0, (loff_t)-1);
+#else
+	truncate_inode_pages(inode->i_mapping, 0);
+	if (inode->i_op->truncate_range)
+		inode->i_op->truncate_range(inode, 0, (loff_t)-1);
+#endif
 
 	obj->madv = __I915_MADV_PURGED;
 }