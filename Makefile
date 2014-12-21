.PHONY: clean All

All:
	@echo "----------构建项目：[PathManagerTest - Debug ]----------"
	@cd "PathManagerTest" && $(MAKE) -f  "PathManagerTest.mk"
clean:
	@echo "----------清理项目：[PathManagerTest - Debug ]----------"
	@cd "PathManagerTest" && $(MAKE) -f  "PathManagerTest.mk" clean
