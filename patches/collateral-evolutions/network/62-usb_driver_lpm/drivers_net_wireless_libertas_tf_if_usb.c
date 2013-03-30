--- a/drivers/net/wireless/libertas_tf/if_usb.c
+++ b/drivers/net/wireless/libertas_tf/if_usb.c
@@ -922,7 +922,9 @@
 	.id_table = if_usb_table,
 	.suspend = if_usb_suspend,
 	.resume = if_usb_resume,
+#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3,5,0))
 	.disable_hub_initiated_lpm = 1,
+#endif
 };
 
 module_usb_driver(if_usb_driver);